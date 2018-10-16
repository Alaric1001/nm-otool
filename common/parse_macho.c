/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_macho.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 13:13:28 by asenat            #+#    #+#             */
/*   Updated: 2018/10/16 10:46:36 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"

uint8_t		parse_macho(const t_map *map, t_macho_data *mdata,
		t_cmd_actions actions)
{
	const t_header64	*header;
	const t_command		*command;
	size_t				shift;
	uint32_t			i;

	header = (const t_header64*)map->addr;
	shift = get_struct_size(HEADER, map->type.mtype);
	i = 0;
	while (i <= get_uint32(header->ncmds, map->type.endian))
	{
		if (!(command = (const t_command*)safe_access(map->addr, shift,
						get_uint32(header->sizeofcmds, map->type.endian)
						+ get_struct_size(HEADER, map->type.mtype))))
			return (0);
		if (!actions(command, map, mdata))
		{
			free_machodata(mdata);
			return (0);
		}
		shift += get_uint32(command->cmdsize, map->type.endian);
		++i;
	}
	return (1);
}

void		free_machodata(t_macho_data *mdata)
{
	t_segment	*seg;
	uint32_t	i;

	i = 0;
	if (mdata->symbols)
	{
		while (i < mdata->symbols->nelems)
			free(*((t_symbol**)mdata->symbols->begin + i++));
		ft_memdel(&mdata->symbols->begin);
	}
	while (mdata->segments)
	{
		free(mdata->segments->sections.begin);
		seg = mdata->segments->next;
		free(mdata->segments);
		mdata->segments = seg;
	}
}
