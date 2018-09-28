/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:33:19 by asenat            #+#    #+#             */
/*   Updated: 2018/09/28 17:33:16 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include "utils/data_structures.h"
# include "opt/opt.h"

# include "libft/output/obuff.h"
# include "libft/memory/memory.h"

typedef struct 	s_symbol
{
	const char		*name;
	const nlist_t	*nlist;
	uint64_t 		value;
}				t_symbol;

uint8_t	get_and_display_symbols(t_opt opt, const t_map *map);
uint8_t	get_static_symbols(const symcommand_t *cmd, const t_map *map,
			t_array *symbold);
void	free_symbols(t_array *symbols);
void	add_value_to_obuff(uint64_t value, t_mtype mtype, t_obuff *obuff);
void	add_type_to_obuff(const nlist_t *nlist, t_obuff *obuff);

#endif
