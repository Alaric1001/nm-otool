/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 17:46:37 by asenat            #+#    #+#             */
/*   Updated: 2018/09/24 19:37:14 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

#include "libft/output/output.h"

#include <sys/mman.h>

t_map	map_file(const t_file *file)
{
	t_map 	ret;

	ret.size = file->stats->st_size;
	ret.addr = mmap(NULL, ret.size, PROT_READ, MAP_PRIVATE, file->fd, 0);
	if (!ret.addr)
		ft_file_error(file->name, "Error while mapping the file");
	return (ret);
}

void 	unmap_file(t_map *map, const t_file *file)
{
	if (munmap(map->addr, map->size) == -1)
		ft_file_error(file->name, "An error occured while unmapping the file");
}
