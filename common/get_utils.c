/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:27:53 by asenat            #+#    #+#             */
/*   Updated: 2018/10/04 15:08:18 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"

uint32_t get_uint32(uint32_t i, t_endianness e)
{
	return (e == BIG ? OSSwapInt32(i) : i);
}

uint64_t get_uint64(uint64_t i, t_endianness e)
{
	return (e == BIG ? OSSwapInt64(i) : i);
}

int32_t get_int32(int32_t i, t_endianness e)
{
	return (e == BIG ? OSSwapInt32(i) : i);
}
