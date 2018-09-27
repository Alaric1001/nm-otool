/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 17:46:37 by asenat            #+#    #+#             */
/*   Updated: 2018/09/27 18:23:48 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "utils/typedefs.h"

#include "libft/output/output.h"

#include <sys/mman.h>
#include <unistd.h>

#define GOOD_CPU 16777223 

static uint8_t *access_macho(const t_fat_arch *arch, const t_map *map)
{
	const t_fat_arch64 *arch64;
	uint64_t offset;

	if (map->type == FAT64)
	{
		arch64 = (const t_fat_arch64*)arch;
		offset = OSSwapInt64(arch64->offset);
	}
	else
		offset = OSSwapInt32(arch->offset);
	return ((uint8_t*)safe_access(map->begin, offset, map->size));
}

static uint8_t parse_fat(t_map *map)
{
	uint32_t			nfat_arch;
	size_t				shift;
	const t_fat_arch	*arch;

	nfat_arch = OSSwapInt32(((const t_fat_header*)map->begin)->nfat_arch);
	shift = sizeof(t_fat_header);
	while (nfat_arch--)
	{
		if (!(arch = (const t_fat_arch*)safe_access(map->begin, shift, map->size)))
			return (0);
		if (arch->cputype == OSSwapInt32(GOOD_CPU))
		{
			if (!(map->addr = access_macho(arch, map)))
				return (0);
			map->type = get_file_type(map);
			return (1);
		}
		shift += get_struct_size(FAT_ARCH, map->type);
	}
	return (1);
}

uint8_t	map_file(const t_file *file, t_map *map)
{
	map->size = file->stats->st_size;
	map->begin = mmap(NULL, map->size, PROT_READ, MAP_PRIVATE, file->fd, 0);
	if (map->addr == MAP_FAILED)
	{
		ft_file_error(file->name, "Error while mapping the file");
		return (0);
	}
	map->addr = map->begin;
	map->type = get_file_type(map);
	if ((map->type == FAT || map->type == FAT64))
	{
		if (parse_fat(map))
			return (1);
		ft_putstr_fd(PARSE_ERR, STDERR_FILENO);
		return (0);
	}
	return (1);
}

void 	unmap_file(t_map *map, const t_file *file)
{
	if (munmap(map->addr, map->size) == -1)
		ft_file_error(file->name, "An error occured while unmapping the file");
}
