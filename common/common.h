/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:30:35 by asenat            #+#    #+#             */
/*   Updated: 2018/10/12 13:48:54 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "common/data_structures.h"
# include "opt/opt.h"

# define PARSE_ERR "The file was not recognized as a valid object file\n"
# define CURRENT_CPU 0x1000007

# define DISPLAY 0x1
# define DISPLAY_CPU 0x2
# define DISPLAY_ARCH 0x4
# define DISPLAY_MULT 0x8

uint8_t		open_file(const char *filename, int oflags, t_file *file);
void		close_file(t_file *file);
uint8_t		map_file(const t_file *file, t_map *map);
void		unmap_file(t_map *map, const t_file *file);
t_type		get_file_type(const t_map *map);
const void	*safe_access(const void *addr, size_t shift, size_t limit);
size_t		get_struct_size(t_mach_struct stype, t_mtype mtype);
uint8_t		get_sections(const t_segcommand *cmd, const t_map *map,
				t_segment **segments);
void		display_sections(const t_segment *s);
void		display_title(const char *fname, const t_map_metadata *metadata,
					uint8_t disp_dat);
uint8_t		split_fat(const t_map *map, t_array *maps);
uint8_t		split_arch(const t_map *map, t_array *maps);
uint8_t		has_different_cpus(const t_array *maps);

uint32_t	get_uint32(uint32_t i, t_endianness e);
uint64_t	get_uint64(uint64_t i, t_endianness e);
int32_t		get_int32(int32_t i, t_endianness e);

typedef uint8_t (*t_cmd_actions)(const t_command *, const t_map*,
					t_macho_data*);
uint8_t		parse_macho(const t_map *map, t_macho_data *mdata,
			t_cmd_actions actions);
void		free_machodata(t_macho_data *mdata);
#endif
