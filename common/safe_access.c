/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:08:39 by asenat            #+#    #+#             */
/*   Updated: 2018/09/25 15:13:00 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"

const void	*safe_access(const void* addr, size_t shift, size_t limit)
{
	if (shift > limit)
		return (NULL);
	return ((const uint8_t*)addr + shift);
}
