/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_uint_to_obuff.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:44:56 by asenat            #+#    #+#             */
/*   Updated: 2018/05/26 17:46:34 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/obuff.h"

void			ft_add_uint_to_obuff(uintmax_t nbr, t_obuff *obuff)
{
	ft_add_uint_base_to_obuff(nbr, "0123456789", obuff);
}
