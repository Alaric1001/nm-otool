/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:27:51 by asenat            #+#    #+#             */
/*   Updated: 2018/10/16 10:33:55 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool/otool.h"

#include "common/common.h"
#include "libft/output/output.h"

#include <unistd.h>
#include <fcntl.h>

uint8_t			sub_otool(t_opt opt, const t_array *maps,
		const t_file *file, uint8_t write_title)
{
	const t_map		*first_map;
	uint32_t		i;

	first_map = (const t_map*)maps->begin;
	i = 0;
	if (!(write_title & DISPLAY_MULT) && maps->nelems > 1)
		write_title += DISPLAY_MULT;
	if (!(write_title & DISPLAY) &&
			(maps->nelems > 1 || first_map[0].metadata.cpu != CURRENT_CPU))
		write_title += DISPLAY;
	if (has_different_cpus(maps))
		write_title += DISPLAY_CPU;
	while (i < maps->nelems)
	{
		if (otool(opt, &first_map[i++], file, write_title))
		{
			free(maps->begin);
			return (1);
		}
	}
	free(maps->begin);
	return (0);
}

uint8_t			otool(t_opt opt, const t_map *map,
		const t_file *file, int title_bytecode)
{
	t_array maps;

	if (map->type.mtype == FAT || map->type.mtype == FAT64)
	{
		if (split_fat(map, &maps))
			return (sub_otool(opt, &maps, file, title_bytecode));
		ft_putstr_fd(PARSE_ERR, STDERR_FILENO);
		return (1);
	}
	if (map->type.mtype == ARCHIVE)
	{
		if (split_arch(map, &maps))
		{
			ft_putstr("Archive : ");
			ft_putendl(file->name);
			return (sub_otool(opt, &maps, file,
						title_bytecode));
		}
		ft_putstr_fd(PARSE_ERR, STDERR_FILENO);
		return (1);
	}
	if (!otool_execute(opt, map, title_bytecode, file->name))
		return (1);
	return (0);
}

static uint8_t	open_map_and_otool(t_opt opt,
		const char *files[], int has_multiple_files)
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
				ret = otool(opt, &mapped_file, &file, has_multiple_files);
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

static uint8_t	has_valid_options(t_opt opt)
{
	return (has_option(opt, OPT_TEXT) || has_option(opt, OPT_TEXT));
}

int				main(int ac, const char *av[])
{
	const char	**files;
	t_args		args;
	t_opt		opt;

	files = NULL;
	args = (t_args) {ac - 1, av + 1};
	opt = parse_options(&args, &files, otool_opt_parser);
	if (opt == OPT_ERR)
		return (1);
	if (!has_option(opt, OPT_FILE))
	{
		ft_putstr_fd("No file specified.\n", STDERR_FILENO);
		return (1);
	}
	if (!has_valid_options(opt))
	{
		ft_putstr_fd("Usage: ./ft_otool -td [File...]\n", 2);
		return (1);
	}
	return (open_map_and_otool(opt, files,
				files[0] && files[1] ? 1 + DISPLAY_MULT : 1));
}
