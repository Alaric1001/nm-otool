/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:43:31 by asenat            #+#    #+#             */
/*   Updated: 2018/09/23 22:05:16 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opt/opt.h"

#include "libft/string/string.h"

#include <stdlib.h>

static t_opt	get_files(int ac, const char * const av[], const char *files[])
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
	files = malloc(j * sizeof(char*));
	while (++i < j)
		files[i] = av[indexes[i]];
	files[i] = 0;
	return (ret);
}

t_opt			parse_options(const t_args *args, const char *files[])
{
	t_opt		ret;
	uint32_t	i;

	ret = 0;
	i = 0;
	while (i < args->count)
	{
		if (!ft_strcmp(args->args[++i], "--"))
		{
			ret |= get_files(args->count - i, &args->args[i + 1], files);
			return (ret);
		}
	}
	ret |= get_files(args->count, args->args, files);
	return (ret);
}
