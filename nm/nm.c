/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:27:48 by asenat            #+#    #+#             */
/*   Updated: 2018/10/09 14:32:15 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm/nm.h"
#include "common/common.h"

#include "libft/output/output.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

static uint8_t	has_different_cpus(const t_array *maps)
{
	const t_map 	*first_map;
	uint32_t		i;
	cpu_type_t		last_cpu;

	first_map = (const t_map*)maps->begin;
	last_cpu = first_map->metadata.cpu;
	i = 1;
	while (i < maps->nelems)
	{
		if (first_map[i].metadata.cpu != last_cpu)
			return (1);
		last_cpu = first_map[i++].metadata.cpu;
	}
	return (0);
}

uint8_t sub_nm(t_opt opt, const t_array *maps, const t_file *file,
		uint8_t write_title)
{
	const t_map 	*first_map;
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
		if (nm(opt, &first_map[i++], file, write_title))
		{
			free(maps->begin);
			return (1);
		}
	}
	free(maps->begin);
	return (0);
}

uint8_t	nm(t_opt opt, const t_map *map, const t_file *file,
		uint8_t write_title)
{
	t_array maps;

	if (map->type.mtype == FAT || map->type.mtype == FAT64)
	{
		if (!split_fat(map, &maps))
			return (1);
		return (sub_nm(opt, &maps, file, write_title));
	}
	if (map->type.mtype == ARCHIVE)
	{
		if (!split_arch(map, &maps))
			return (1);
		return (sub_nm(opt, &maps, file, write_title + DISPLAY_MULT));
	}
	if (write_title & DISPLAY)
		display_title(file->name, &map->metadata, write_title);
	if (!get_and_display_symbols(opt, map))
		return (1);
	return (0);
}

static int open_map_and_nm(t_opt opt, const char *files[], int has_multiple_files)
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
				if ((ret = nm(opt, &mapped_file, &file, has_multiple_files)))
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
		ret = open_map_and_nm(opt, files, files[0] && files[1] ? 1 : 0);
	else
		ret = open_map_and_nm(opt, (const char*[]){"./a.out"}, 0);
	free(files);
	return (ret);
}
