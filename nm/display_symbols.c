/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_symbols.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:40:11 by asenat            #+#    #+#             */
/*   Updated: 2018/10/11 13:35:30 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm/nm.h"
#include "common/common.h"
#include "libft/output/obuff.h"

static uint8_t	parse_command(const t_command *command, const t_map *map,
					t_macho_data *mdata)
{
	uint32_t command_id;

	command_id = get_uint32(command->cmd, map->type.endian);
	if (command_id == LC_SEGMENT || command_id == LC_SEGMENT_64)
	{
		return (get_sections((const t_segcommand*)command,
					map, &mdata->segments));
	}
	if (command_id == LC_SYMTAB)
	{
		return (get_static_symbols((const t_symcommand*)command,
					map, mdata->symbols));
	}
	return (1);
}

static void		display_symbols(t_opt opt, const t_macho_data *data,
					t_type type)
{
	size_t			i;
	t_obuff			obuff;
	const t_symbol	**sym;

	i = 0;
	(void)opt;
	obuff = (t_obuff){.cursor = 0, .fd = 1};
	while (i < data->symbols->nelems)
	{
		sym = (const t_symbol**)data->symbols->begin + i;
		if ((*sym)->name)
		{
			add_value_to_obuff((*sym)->value, type.mtype,
					(*sym)->nlist, &obuff);
			ft_add_char_to_obuff(' ', &obuff);
			add_type_to_obuff((*sym), data->segments, &obuff);
			ft_add_char_to_obuff(' ', &obuff);
			ft_add_str_to_obuff((*sym)->name, &obuff);
			ft_add_char_to_obuff('\n', &obuff);
			ft_flush_obuff(&obuff);
		}
		++i;
	}
	ft_flush_obuff(&obuff);
}

uint8_t			get_and_display_symbols(t_opt opt, const t_map *map)
{
	t_array			symbols;
	t_macho_data	mdata;

	symbols = (t_array){0, sizeof(t_symbol*), NULL};
	mdata = (t_macho_data){&symbols, NULL};
	if (map->type.mtype == NONE)
		return (0);
	if (!parse_macho(map, &mdata, parse_command))
		return (0);
	sort_symbols(opt, &symbols);
	display_symbols(opt, &mdata, map->type);
	free_machodata(&mdata);
	return (1);
}
