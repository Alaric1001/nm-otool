/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_int_to_buff.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:08:23 by asenat            #+#    #+#             */
/*   Updated: 2018/05/26 17:48:37 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/obuff.h"

void	ft_add_int_to_obuff(int n, t_obuff *obuff)
{
	unsigned int i;

	if (n < 0)
	{
		ft_add_char_to_obuff('-', obuff);
		i = -n;
	}
	else
		i = n;
	if (i >= 10)
	{
		ft_add_int_to_obuff((i / 10), obuff);
		ft_add_int_to_obuff((i % 10), obuff);
	}
	else
		ft_add_char_to_obuff(i + '0', obuff);
}
