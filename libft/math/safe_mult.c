/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 15:38:45 by asenat            #+#    #+#             */
/*   Updated: 2018/09/10 10:44:09 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math/math.h"

/*
** multiply a and b.
** If the multiplication result overflow, *overflow is set to 1
*/

size_t		safe_u_mult(size_t a, size_t b, uint8_t *overflow)
{
	__uint128_t mult;

	*overflow = 0;
	mult = (__uint128_t)a * (__uint128_t)b;
	if (mult >> sizeof(size_t) * 8)
		*overflow = 1;
	return (mult);
}

intmax_t	safe_mult(intmax_t a, intmax_t b, uint8_t *overflow)
{
	__uint128_t mult;

	*overflow = 0;
	mult = (__uint128_t)a * (__uint128_t)b;
	if (mult >> sizeof(intmax_t) * 8)
		*overflow = 1;
	return (mult);
}
