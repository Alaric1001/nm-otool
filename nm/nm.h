/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:33:19 by asenat            #+#    #+#             */
/*   Updated: 2018/10/16 13:29:53 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include "common/data_structures.h"
# include "opt/opt.h"

# include "libft/output/obuff.h"

uint8_t			get_and_display_symbols(t_opt opt, const t_map *map);
uint8_t			get_static_symbols(const t_symcommand *cmd,
					const t_map *map, t_array *symbold);
void			add_value_to_obuff(uint64_t value, t_mtype mtype,
					const t_nlist *nlist, t_obuff *obuff);
void			add_type_to_obuff(const t_symbol *symbol,
					const t_segment *segments, t_obuff *obuff);
void			add_name_to_obuff(const char *name, t_endianness e,
					t_obuff *obuff);
void			sort_symbols(t_opt opt, t_array *symbols);

uint8_t			nm(t_opt opt, const t_map *map, const t_file *file,
					uint8_t write_title);
uint8_t			sub_nm(t_opt opt, const t_array *maps, const t_file *file,
					uint8_t write_title);

# define OPT_REVERSE 0x2
# define OPT_NO_SORT 0x4
# define OPT_ONLY_UNDF 0x8
# define OPT_NO_UNDF 0x10
# define OPT_JUST_SYM 0x20

t_opt			nm_opt_parser(t_opt curr_opt, const char *arg);
#endif
