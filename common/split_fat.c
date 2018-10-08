/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_fat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:17:54 by asenat            #+#    #+#             */
/*   Updated: 2018/10/08 13:50:23 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"
#include "common/typedefs.h"

static uint8_t get_fat(const t_fat_arch *arch, const t_map *origin, t_map *map)
{
	const t_fat_arch64	*arch64;
	uint64_t 			offset;
	uint64_t 			size;

	if (origin->type.mtype == FAT64)
	{
		arch64 = (const t_fat_arch64*)arch;
		offset = get_uint64(arch64->offset, origin->type.endian);
		size = get_uint64(arch64->size, origin->type.endian);
	}
	else
		offset = get_uint32(arch->offset, origin->type.endian);
		size = get_uint32(arch->size, origin->type.endian);
	if (!(map->addr = (void*)safe_access(origin->addr, offset, origin->size)))
		return (0);
	map->size = size;
	map->type = get_file_type(map);
	map->metadata.cpu = get_uint32(arch->cputype, origin->type.endian);
	return (1);
}

static int check_cpu(const t_fat_arch *arch, const t_map *map, t_array *maps)
{
	if (arch->cputype == get_int32(CURRENT_CPU, map->type.endian))
	{
		if (!(get_fat(arch, map, (t_map*)(maps->begin))))
			return (-1);
		maps->nelems = 1;
		return (1);
	}
	return (0);
}

static uint32_t get_narch(const t_map *map)
{
	return (get_uint32(((const t_fat_header*)map->addr)->nfat_arch,
				map->type.endian));
}

uint8_t		split_fat(const t_map *map, t_array *maps)
{
	uint32_t			nfat_arch;
	size_t				shift;
	const t_fat_arch	*arch;
	int					i;
	int					r;

	nfat_arch = get_narch(map);
	maps->nelems = nfat_arch;
	maps->begin = ft_memalloc(sizeof(t_map) * nfat_arch);
	shift = sizeof(t_fat_header);
	i = 0;
	while (nfat_arch--)
	{
		if (!(arch = (const t_fat_arch*)safe_access(map->addr,
						shift, map->size)))
			return (0);
		if ((r = check_cpu(arch, map, maps)))
			break ;
		else if (r == -1)
			return (0);
		if (!(get_fat(arch, map, (t_map*)(maps->begin) + i++)))
			return (0);
		shift += get_struct_size(FAT_ARCH, map->type.mtype);
	}
	return (1);
}
