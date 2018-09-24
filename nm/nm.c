/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:27:48 by asenat            #+#    #+#             */
/*   Updated: 2018/09/24 16:01:12 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "opt/opt.h"

#include "libft/output/output.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

static int nm(t_opt opt, const char *files[])
{
	int		ret;
	t_file	file;

	ret = 0;
	(void)opt;
	while (*files)
	{
		if (!open_file(*files, O_RDONLY, &file))
			ret = 1;
		else
		{
			printf("name:%s, fd:%d, size:%lld\n", file.name, file.fd, file.stats->st_size);
			close_file(&file);
		}
		++files;
	}
	return (ret);
}

int			main(int ac, const char *av[])
{
	int			ret;
	const char	**files;
	t_args		args;
	t_opt		opt;

	files = NULL;
	args = (t_args) {ac - 1, av + 1};
	opt = parse_options(&args, &files);
	if (has_option(opt, OPT_FILE))
		ret = nm(opt, files);
	else
		ret = nm(opt, (const char*[]){"./a.out", 0});
	free(files);
	return (ret);
}
