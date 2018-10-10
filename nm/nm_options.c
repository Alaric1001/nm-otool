/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:20:29 by asenat            #+#    #+#             */
/*   Updated: 2018/10/10 17:26:49 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm/nm.h"

#include "opt/opt.h"
#include "libft/string/string.h"

t_opt	nm_opt_parser(t_opt curr_opt, const char *arg)
{
	t_opt ret;

	ret = 0;
	(void)curr_opt;
	if (!ft_strcmp(arg, "-r"))
		ret += OPT_REVERSE;
	return (ret);
}
