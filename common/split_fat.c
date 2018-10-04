/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_fat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:17:54 by asenat            #+#    #+#             */
/*   Updated: 2018/10/03 18:58:10 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"
#include "common/typedefs.h"

#define GOOD_CPU 16777223

//static void try_to_set_map(const t_map *ref, t_map *array, int *i)
//{
//	int j;
//
//	j = 0;
//	while (j < *i)
//	{
//		if (array[j].cpu_type == ref->cpu_type)
//		{
//			if (ref->type > array[j].type)
//				ft_memcpy(&array[j], &ref, sizeof(t_map));
//			else
//				*i++;
//			return;
//		}
//	}
//}
//
//static uint8_t get_fat(const t_fat_arch *arch, const t_map *origin, t_map *array, int *i)
//{
//	const t_fat_arch64 *arch64;
//	t_map tmp;
//	uint64_t offset;
//
//	tmp.cpu_type = OSSwapInt32(arch->cputype);
//	if (map->type == FAT64)
//	{
//		arch64 = (const t_fat_arch64*)arch;
//		offset = OSSwapInt64(arch64->offset);
//		tmp.size = OSSwapInt64(arch64->size);
//	}
//	else
//		offset = OSSwapInt32(arch->offset);
//		tmp.size = OSSwapInt32(arch->size);
//	if (!(tmp.addr = (void*)safe_access(origin->addr, offset, origin->size)))
//		return (0);
//	tmp.type = get_file_type(&tmp);
//	try_to_set_map(&tmp, array, i);
//	return (1);
//}

static uint8_t get_fat(const t_fat_arch *arch, const t_map *origin, t_map *map)
{
	const t_fat_arch64 *arch64;
	uint64_t offset;
	uint64_t size;

	if (map->type == FAT64)
	{
		arch64 = (const t_fat_arch64*)arch;
		offset = OSSwapInt64(arch64->offset);
		size = OSSwapInt64(arch64->size);
	}
	else
		offset = OSSwapInt32(arch->offset);
		size = OSSwapInt32(arch->size);
	if (!(map->addr = (void*)safe_access(origin->addr, offset, origin->size)))
		return (0);
	map->size = size;
	map->type = get_file_type(map);
	return (1);
}

static int check_cpu(const t_fat_arch *arch, const t_map *map, t_array *maps)
{
	if (arch->cputype == OSSwapInt32(GOOD_CPU))
	{
		if (!(get_fat(arch, map, (t_map*)(maps->begin))))
			return (-1);
		maps->nelems = 1;
		return (1);
	}
	return (0);
}

uint8_t		split_fat(const t_map *map, t_array *maps)
{
	uint32_t			nfat_arch;
	size_t				shift;
	const t_fat_arch	*arch;
	int					i;
	int					r;

	nfat_arch = OSSwapInt32(((const t_fat_header*)map->addr)->nfat_arch);
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
		shift += get_struct_size(FAT_ARCH, map->type);
	}
	return (1);
}
