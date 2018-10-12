/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:54:40 by asenat            #+#    #+#             */
/*   Updated: 2018/10/12 15:55:33 by asenat           ###   ########.fr       */
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

uint8_t		otool_execute(t_opt opt, const t_map *map)
{
	t_macho_data	mdata;
	uint8_t			ret;

	mdata = (t_macho_data){NULL, NULL};
	ret = 0;
	if (map->type.mtype != NONE)
	{
		if (parse_macho(map, &mdata, parse_command))
		{
			if (has_option(opt, OPT_TEXT))
				ret = display_section(map, &mdata, SECT_TEXT);
			else if (has_option(opt, OPT_DATA))
				ret = display_section(map, &mdata, SECT_DATA);
			else
				ft_putstr_fd("Usage: ./ft_otool -td [File...]\n", 2);
			free_machodata(&mdata);
			return (ret);
		}
	}
	free_machodata(&mdata);
	ft_putstr_fd(PARSE_ERR, STDERR_FILENO);
	return (0);
	
}
