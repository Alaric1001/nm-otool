/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:30:35 by asenat            #+#    #+#             */
/*   Updated: 2018/10/03 17:06:27 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "common/data_structures.h"

# define PARSE_ERR "The file was not recognized as a valid object file\n"

uint8_t		open_file(const char *filename, int oflags, t_file *file);
void		close_file(t_file *file);
uint8_t		map_file(const t_file *file, t_map *map);
void		unmap_file(t_map *map, const t_file *file);
t_mtype		get_file_type(const t_map *map);
const void	*safe_access(const void* addr, size_t shift, size_t limit);
size_t		get_struct_size(t_mach_struct stype, t_mtype mtype);
uint8_t		get_sections(const t_segcommand *cmd, const t_map *map,
				t_segment **segments);
void 		display_sections(const t_segment *s);
uint8_t		split_fat(const t_map *map, t_array *maps);

#endif
