/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:19:10 by asenat            #+#    #+#             */
/*   Updated: 2018/10/16 10:26:58 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_H
# define OTOOL_H

# include "opt/opt.h"
# include "common/common.h"

# include "libft/memory/memory.h"

# define OPT_TEXT 0x2
# define OPT_DATA 0x4

t_opt		otool_opt_parser(t_opt curr_opt, const char *arg);
uint8_t		otool(t_opt opt, const t_map *map, const t_file *file,
					int write_title);
uint8_t		sub_otool(t_opt opt, const t_array *maps, const t_file *file,
				uint8_t write_title);
uint8_t		display_section(const t_map *map, const t_macho_data *data,
				const char *sect);
uint8_t		otool_execute(t_opt opt, const t_map *map,
		uint8_t title_data, const char *file_name);

typedef struct s_obuff	t_obuff;
void		add_uint_to_obuff(uint32_t nb, size_t size, t_endianness e,
				t_obuff *obuff);
void		add_addr_to_obuff(uint64_t addr, t_mtype mtype, t_obuff *obuff);
#endif
