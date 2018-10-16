/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:27:53 by asenat            #+#    #+#             */
/*   Updated: 2018/10/16 16:11:45 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"

#include "libft/memory/memory.h"

uint32_t	get_uint32(uint32_t i, t_endianness e)
{
	return (e == BIG ? ft_swap_uint32(i) : i);
}

uint64_t	get_uint64(uint64_t i, t_endianness e)
{
	return (e == BIG ? ft_swap_uint64(i) : i);
}

int32_t		get_int32(int32_t i, t_endianness e)
{
	return (e == BIG ? ft_swap_int32(i) : i);
}
