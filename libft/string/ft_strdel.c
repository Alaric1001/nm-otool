/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:18:38 by asenat            #+#    #+#             */
/*   Updated: 2016/11/10 13:37:09 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

#include <stdlib.h>

void	ft_strdel(char **ap)
{
	if (!ap)
		return ;
	free(*ap);
	*ap = NULL;
}
