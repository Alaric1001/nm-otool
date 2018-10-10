/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_symbols.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:25:38 by asenat            #+#    #+#             */
/*   Updated: 2018/10/10 14:17:57 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm/nm.h"

#include "libft/string/string.h"
#include "libft/math/math.h"

static int		cmp(const t_symbol **a, const t_symbol **b)
{
	int ret;

	ret = ft_strcmp((*a)->name, (*b)->name);
	if (!ret)
		return ((*a)->value - (*b)->value);
	return (ret);
}

void			sort_symbols(t_array *symbols)
{
	ft_qsort(symbols, (int (*)(const void*, const void*))cmp);
}
