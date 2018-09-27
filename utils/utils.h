/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:30:35 by asenat            #+#    #+#             */
/*   Updated: 2018/09/27 16:22:12 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "utils/data_structures.h"

# define PARSE_ERR "The file was not recognized as a valid object file\n"

uint8_t		open_file(const char *filename, int oflags, t_file *file);
void		close_file(t_file *file);
uint8_t		map_file(const t_file *file, t_map *map);
void		unmap_file(t_map *map, const t_file *file);
t_mtype		get_file_type(const t_map *map);
const void	*safe_access(const void* addr, size_t shift, size_t limit);
size_t		get_struct_size(t_mach_struct stype, t_mtype mtype);

#endif
