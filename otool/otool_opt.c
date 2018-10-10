/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:18:40 by asenat            #+#    #+#             */
/*   Updated: 2018/10/10 18:22:58 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool/otool.h"

#include "libft/string/string.h"
#include "libft/output/output.h"

static void	unknown_cmd(const char *cmd)
{
		ft_putstr_fd("Unknown command line argument '", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd("'.\n", STDERR_FILENO);
}

t_opt		otool_opt_parser(t_opt curr_opt, const char *arg)
{
	t_opt ret;

	ret = 0;
	(void)curr_opt;
	if (!ft_strcmp(arg, "-t"))
		ret += OPT_TEXT;
	else if (arg[0] == '-')
	{
		unknown_cmd(arg);
		return (-1);
	}
	return (ret);
}
