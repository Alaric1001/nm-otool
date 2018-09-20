/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char_to_obuff.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:29:55 by asenat            #+#    #+#             */
/*   Updated: 2018/09/07 15:54:56 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/obuff.h"

void	ft_add_char_to_obuff(char c, t_obuff *obuff)
{
	if (obuff->cursor == LIBFT_OBUF_SIZE)
		ft_flush_obuff(obuff);
	obuff->buffer[obuff->cursor++] = c;
}
