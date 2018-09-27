/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:27:48 by asenat            #+#    #+#             */
/*   Updated: 2018/09/27 17:11:51 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm/nm.h"
#include "utils/utils.h"

#include "libft/output/output.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

static int nm(t_opt opt, const char *files[])
{
	int		ret;
	t_file	file;
	t_map	mapped_file;

	ret = 0;
	(void)opt;
	while (*files)
	{
		if (open_file(*files, O_RDONLY, &file))
		{
			if (map_file(&file, &mapped_file))
			{
				printf("name:%s, fd:%d, size:%lld\n", file.name, file.fd, file.stats->st_size);
				if (!get_and_display_symbols(opt, &mapped_file))
					ft_putstr_fd(PARSE_ERR,	STDERR_FILENO);
				unmap_file(&mapped_file, &file);
			}
			close_file(&file);
		}
		else
			ret = 1;
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
