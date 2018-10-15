/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_obuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 12:10:18 by asenat            #+#    #+#             */
/*   Updated: 2018/10/15 12:47:58 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool/otool.h"

#include "common/common.h"
#include "libft/output/obuff.h"
#include "libft/math/math.h"

void		add_uint_to_obuff(uint32_t nb, size_t size, t_endianness e,
				t_obuff* obuff)
{
	size_t	nb_len;
	int		padding;

	
	if (size > sizeof(uint8_t))
		nb = get_uint32(nb, e);
	nb_len = ft_get_u_nb_len(nb, 16) + 1;
	padding = (size * 8 / 4) - nb_len;
	while (padding-- > 0)
		ft_add_char_to_obuff('0', obuff);
	ft_add_uint_base_to_obuff(nb, LIBFT_FMT_HEX, obuff);
	ft_add_char_to_obuff(' ', obuff);
}

void		add_addr_to_obuff(uint64_t addr, t_mtype mtype, t_obuff* obuff)
{
	size_t	addr_len;
	int		padding;

	addr_len = ft_get_u_nb_len(addr, 16) + 1;
	if (mtype == MACHO64)
		padding = 16 - addr_len;
	else
		padding = 8 - addr_len;
	while (padding-- > 0)
		ft_add_char_to_obuff('0', obuff);
	ft_add_uint_base_to_obuff(addr, LIBFT_FMT_HEX, obuff);
	ft_add_char_to_obuff('\t', obuff);
} 
