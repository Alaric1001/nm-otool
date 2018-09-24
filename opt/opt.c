/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:43:31 by asenat            #+#    #+#             */
/*   Updated: 2018/09/24 16:53:05 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opt/opt.h"

#include "libft/string/string.h"
#include "libft/memory/memory.h"

#include <stdlib.h>

static t_opt	get_files(int ac, const char * const av[],
		const char **files[])
{
	t_opt	ret;
	int		i;
	int		j;
	int		indexes[ac];

	ret = 0;
	i = -1;
	j = 0;
	while (++i < ac)
	{
		if (av[i][0] != '-')
			indexes[j++] = i;
	}
	if (!j)
		return (ret);
	ret = OPT_FILE;
	i = -1;
	*files = ft_malloc_or_panic((j + 1) * sizeof(char*));
	while (++i < j)
		(*files)[i] = av[indexes[i]];
	(*files)[i] = 0;
	return (ret);
}

t_opt			parse_options(const t_args *args, const char **files[])
{
	t_opt		ret;
	uint32_t	i;

	ret = 0;
	i = 0;
	while (i < args->count)
	{
		if (!ft_strcmp(args->args[++i], "--"))
			break ;
	}
	ret |= get_files(args->count, args->args, files);
	return (ret);
}

uint8_t		has_option(t_opt opt, uint32_t option)
{
	return (opt & option);
}
