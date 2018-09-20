/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flush_obuff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:28:36 by asenat            #+#    #+#             */
/*   Updated: 2018/09/11 15:16:01 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/obuff.h"

#include "output/output.h"
#include "memory/memory.h"

void	ft_flush_obuff(t_obuff *obuff)
{
	size_t i;

	i = 0;
	while (i < LIBFT_OBUF_SIZE && obuff->buffer[i])
		++i;
	ft_putnstr_fd(obuff->buffer, i, obuff->fd);
	ft_bzero(obuff->buffer, LIBFT_OBUF_SIZE);
	obuff->cursor = 0;
}
