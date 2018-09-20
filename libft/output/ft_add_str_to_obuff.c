/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str_to_obuff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:29:22 by asenat            #+#    #+#             */
/*   Updated: 2018/05/26 17:43:29 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/obuff.h"

void	ft_add_str_to_obuff(char const *str, t_obuff *obuff)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (obuff->cursor == LIBFT_OBUF_SIZE)
			ft_flush_obuff(obuff);
		obuff->buffer[obuff->cursor++] = str[i++];
	}
}
