/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:54:40 by asenat            #+#    #+#             */
/*   Updated: 2018/10/12 18:38:20 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool/otool.h"

#include "common/common.h"
#include "libft/output/output.h"

#include <unistd.h>

static uint8_t parse_command(const t_command *command, const t_map *map,
				t_macho_data *mdata)
{
	uint32_t command_id;

	command_id = get_uint32(command->cmd, map->type.endian);
	if (command_id == LC_SEGMENT || command_id == LC_SEGMENT_64)
	{
		return (get_sections((const t_segcommand*)command,
					map, &mdata->segments));
	}
	return (1);
}

static void not_an_object(const char *fname)
{
	ft_putstr(fname);
	ft_putstr(": is not an object file\n");
}

uint8_t		otool_execute(t_opt opt, const t_map *map,
		uint8_t title_data, const char *file_name)
{
	t_macho_data	mdata;
	uint8_t			ret;

	mdata = (t_macho_data){NULL, NULL};
	ret = 0;
	if (map->type.mtype != NONE)
	{
		if (parse_macho(map, &mdata, parse_command))
		{
			display_title(file_name, &map->metadata, title_data);
			if (has_option(opt, OPT_TEXT))
				ret = display_section(map, &mdata, SECT_TEXT);
			if (has_option(opt, OPT_DATA))
				ret = display_section(map, &mdata, SECT_DATA);
			free_machodata(&mdata);
			return (ret);
		}
	}
	not_an_object(file_name);
	free_machodata(&mdata);
	return (0);
}
