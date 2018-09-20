/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 08:38:58 by asenat            #+#    #+#             */
/*   Updated: 2018/05/26 16:36:11 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/output.h"

#include <unistd.h>

int		ft_putnstr(char const *str, size_t n)
{
	return (ft_putnstr_fd(str, n, 1));
}
