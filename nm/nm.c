/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:27:48 by asenat            #+#    #+#             */
/*   Updated: 2018/10/04 17:34:58 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm/nm.h"
#include "common/common.h"

#include "libft/output/output.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

static uint8_t nm_multi_map(t_opt opt, const t_array *maps, const t_file *file)
{
	const t_map 	*first_map;
	uint32_t		i;

	i = 0;
	first_map = (const t_map*)maps->begin;
	while (i < maps->nelems)
	{
		if (maps->nelems > 1 || first_map[i].cpu_type != CURRENT_CPU)
			display_title(file->name, first_map[i].cpu_type);
		if (!get_and_display_symbols(opt, &first_map[i++]))
		{
			free(maps->begin);
			return (1);
		}
	}
	free(maps->begin);
	return (0);
}

static uint8_t	nm(t_opt opt, const t_map *mapped_file, const t_file *file)
{
	t_array maps;

	if (mapped_file->type.mtype == FAT || mapped_file->type.mtype == FAT64)
	{
		if (!(split_fat(mapped_file, &maps)))
			return (1);
		return (nm_multi_map(opt, &maps, file));
	}
	if (!get_and_display_symbols(opt, mapped_file))
		return (1);
	return (0);
}

static int open_map_and_nm(t_opt opt, const char *files[])
{
	int		ret;
	t_file	file;
	t_map	mapped_file;

	ret = 0;
	while (*files)
	{
		if (open_file(*files, O_RDONLY, &file))
		{
			if (map_file(&file, &mapped_file))
			{
				if ((ret = nm(opt, &mapped_file, &file)))
					ft_putstr_fd(PARSE_ERR,	STDERR_FILENO);
				//if (!get_and_display_symbols(opt, &mapped_file))
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
		ret = open_map_and_nm(opt, files);
	else
		ret = open_map_and_nm(opt, (const char*[]){"./a.out", 0});
	free(files);
	return (ret);
}
