/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:43:31 by asenat            #+#    #+#             */
/*   Updated: 2018/10/10 18:07:34 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opt/opt.h"

#include "libft/string/string.h"
#include "libft/memory/memory.h"

#include <stdlib.h>

static t_opt	get_files(int ac, const char *const av[],
		const char **files[])
{
	int		i;
	int		j;
	int		indexes[ac];
	int		store_opt_too;

	i = -1;
	j = 0;
	store_opt_too = 0;
	while (++i < ac)
	{
		if (store_opt_too || av[i][0] != '-')
			indexes[j++] = i;
		if (av[i][0] == '-' && av[i][1] == '-')
			store_opt_too = 1;
	}
	if (!j)
		return (0);
	i = -1;
	*files = ft_malloc_or_panic((j + 1) * sizeof(char*));
	while (++i < j)
		(*files)[i] = av[indexes[i]];
	(*files)[i] = 0;
	return (OPT_FILE);
}

t_opt			parse_options(const t_args *args, const char **files[],
					t_opt (*opt_parser)(t_opt opt, const char *arg))
{
	t_opt		ret;
	uint32_t	i;

	ret = 0;
	i = 0;
	while (i < args->count)
	{
		if (!ft_strcmp(args->args[i], "--"))
			break ;
		if ((ret += opt_parser(ret, args->args[i++])) == (t_opt)-1)
			return (OPT_ERR);
	}
	ret += get_files(args->count, args->args, files);
	return (ret);
}

uint8_t			has_option(t_opt opt, uint32_t option)
{
	return (opt & option);
}
