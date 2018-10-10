/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:27:51 by asenat            #+#    #+#             */
/*   Updated: 2018/10/10 18:45:14 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool/otool.h"

#include "common/common.h"
#include "libft/output/output.h"

#include <unistd.h>

int main(int ac, const char *av[]) {
	const char	**files;
	t_args		args;
	t_opt		opt;

	files = NULL;
	args = (t_args) {ac - 1, av + 1};
	opt = parse_options(&args, &files, otool_opt_parser);
	if (opt == OPT_ERR)
		return (1);
	if (!has_option(opt, OPT_TEXT))
	{
		ft_putstr_fd("No options specified.\n", STDERR_FILENO);
		return (1);
	}
	if (!has_option(opt, OPT_FILE))
	{
		ft_putstr_fd("No file specified.\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}
