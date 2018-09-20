/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:04:32 by asenat            #+#    #+#             */
/*   Updated: 2018/05/26 16:34:01 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/output.h"

#include "string/string.h"
#include <unistd.h>

int		ft_putnstr_fd(char const *str, size_t n, int fd)
{
	char const *tmp;

	if (!str)
		return (0);
	tmp = str;
	while (n-- && str)
		tmp++;
	write(fd, str, tmp - str);
	return (tmp - str);
}
