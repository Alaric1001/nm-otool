/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_nstr_to_obuff.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:36:58 by asenat            #+#    #+#             */
/*   Updated: 2018/05/26 17:38:38 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/obuff.h"

void	ft_add_nstr_to_obuff(char const *str, size_t n, t_obuff *obuff)
{
	size_t i;

	i = 0;
	while (str[i] && i != n)
	{
		if (obuff->cursor == LIBFT_OBUF_SIZE)
			ft_flush_obuff(obuff);
		obuff->buffer[obuff->cursor++] = str[i++];
	}
}
