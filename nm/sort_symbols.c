/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_symbols.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:25:38 by asenat            #+#    #+#             */
/*   Updated: 2018/10/16 12:18:41 by asenat           ###   ########.fr       */
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

static int		r_cmp(const t_symbol **a, const t_symbol **b)
{
	return (-cmp(a, b));
}

void			sort_symbols(t_opt opt, t_array *symbols)
{
	if (has_option(opt, OPT_NO_SORT))
		return ;
	if (has_option(opt, OPT_REVERSE))
		ft_qsort(symbols, (int (*)(const void*, const void*))r_cmp);
	else
		ft_qsort(symbols, (int (*)(const void*, const void*))cmp);
}
