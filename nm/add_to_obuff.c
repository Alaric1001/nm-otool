/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_obuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 17:23:56 by asenat            #+#    #+#             */
/*   Updated: 2018/09/27 15:14:57 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm/nm.h"

#include "libft/math/math.h"

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

void	add_type_to_obuff(const nlist_t *nlist, t_obuff *obuff)
{
	(void)nlist;
	ft_add_char_to_obuff('U', obuff);
}
