/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:25:14 by asenat            #+#    #+#             */
/*   Updated: 2018/09/10 10:42:07 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# include <stdlib.h>

size_t		ft_getnblen(unsigned long long n);
size_t		safe_u_mult(size_t a, size_t b, uint8_t *overflow);
intmax_t	safe_mult(intmax_t a, intmax_t b, uint8_t *overflow);

#endif
