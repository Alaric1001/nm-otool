/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_uint_base_to_obuff.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:33:00 by asenat            #+#    #+#             */
/*   Updated: 2018/09/07 15:55:28 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/obuff.h"

#include "memory/memory.h"
#include "string/string.h"

void	ft_add_uint_base_to_obuff(uintmax_t nb, const char *format,
									t_obuff *obuff)
{
	uintmax_t	tmp;
	char		buf[16];
	size_t		base;
	int			i;

	ft_bzero(&buf, 16);
	base = ft_strlen(format);
	i = 0;
	tmp = nb;
	if (!nb)
		buf[0] = '0';
	while ((tmp /= base))
		++i;
	while (nb)
	{
		buf[i--] = format[nb % base];
		nb /= base;
	}
	if (base != 10)
		ft_add_str_to_obuff("0x", obuff);
	ft_add_nstr_to_obuff(buf, 16, obuff);
}
