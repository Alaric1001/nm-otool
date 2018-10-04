/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_obuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 17:23:56 by asenat            #+#    #+#             */
/*   Updated: 2018/10/03 13:32:03 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm/nm.h"

#include "libft/math/math.h"
#include "libft/string/string.h"

#define VALUE_MAX_LEN64 16
#define VALUE_MAX_LEN32 8

void	add_value_to_obuff(uint64_t value, t_mtype mtype, t_obuff *obuff)
{
	size_t	value_len;
	char	c;
	int		padding;

	value_len = ft_get_u_nb_len(value, 16);
	if (value)
	{
		++value_len;
		c = '0';
	}
	else
		c = ' ';
	if (mtype == MACHO64)
		padding = VALUE_MAX_LEN64 - value_len;
	else
		padding = VALUE_MAX_LEN32 - value_len;
	while (padding-- > 0)
 		ft_add_char_to_obuff(c, obuff);
	if (value)
		ft_add_uint_base_to_obuff(value, LIBFT_FMT_HEX, obuff);
}

static char corresponding_char(const t_segment *segments, uint32_t index)
{
	const char		*name;
	const t_section	*begin;

	while (segments)
	{
		if (index <= segments->sections.nelems && segments->sections.nelems)
		{
			begin = (const t_section*)segments->sections.begin;
			name = begin[index].name;
			if (!ft_strcmp(SECT_TEXT, name))
				return ('T');
			if (!ft_strcmp(SECT_DATA, name))
				return ('D');
			if (!ft_strcmp(SECT_BSS, name))
				return ('B');
			return ('S');
		}
		index -= segments->sections.nelems;
		segments = segments->next;
	}
	return ('?');
}

void	add_type_to_obuff(const t_nlist *nlist, const t_segment *segments,
			t_obuff *obuff)
{
	char type;

	type = 'U';
	if ((nlist->n_type & N_TYPE) == N_ABS)
		type = 'A';
	else if ((nlist->n_type & N_TYPE) == N_INDR)
		type = 'I';
	else if ((nlist->n_type & N_TYPE) == N_SECT)
		type = corresponding_char(segments, nlist->n_sect - 1);
	if (!(nlist->n_type & N_EXT))
		type = ft_tolower(type);
	ft_add_char_to_obuff(type, obuff);
}
