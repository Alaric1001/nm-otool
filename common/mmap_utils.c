/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 17:46:37 by asenat            #+#    #+#             */
/*   Updated: 2018/10/03 16:12:48 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"
#include "common/typedefs.h"

#include "libft/output/output.h"

#include <sys/mman.h>
#include <unistd.h>

uint8_t	map_file(const t_file *file, t_map *map)
{
	map->size = file->stats->st_size;
	map->addr = mmap(NULL, map->size, PROT_READ, MAP_PRIVATE, file->fd, 0);
	if (map->addr == MAP_FAILED)
	{
		ft_file_error(file->name, "Error while mapping the file");
		return (0);
	}
	map->type = get_file_type(map);
	return (1);
}

void 	unmap_file(t_map *map, const t_file *file)
{
	if (munmap(map->addr, map->size) == -1)
		ft_file_error(file->name, "An error occured while unmapping the file");
}
