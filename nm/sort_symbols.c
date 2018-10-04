/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_symbols.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:25:38 by asenat            #+#    #+#             */
/*   Updated: 2018/10/03 14:05:36 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm/nm.h"

#include "libft/string/string.h"

static int		cmp(const t_symbol *a, const t_symbol *b)
{
	int ret;

	ret = ft_strcmp(a->name, b->name);
	if (!ret)
		return (a->value - b->value);
	return (ret);
}

void			sort_symbols(t_array *symbols)
{
	uint32_t 	i;
	uint32_t	j;
	t_symbol	**ptr;
	t_symbol	*tmp;

	i = 0;
	ptr = (t_symbol**)symbols->begin;
	while (i < symbols->nelems)
	{
		j = i;
		while (j > 0 && cmp(ptr[j], ptr[j - 1]) < 0)
		{
			tmp = ptr[j];
			ptr[j] = ptr[j - 1];
			ptr[j - 1] = tmp;
			--j;
		}
		++i;
	}
}
