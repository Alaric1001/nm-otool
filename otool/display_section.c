/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_section.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 14:09:44 by asenat            #+#    #+#             */
/*   Updated: 2018/10/15 15:59:57 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool/otool.h"

#include "common/common.h"
#include "libft/string/string.h"
#include "libft/output/output.h"
#include "libft/output/obuff.h"

#include <unistd.h>

static const t_section *get_section_and_segname(const t_segment *segments,
		const char *sect, const char **seg)
{
	const t_section		*section;
	unsigned int		i;

	while (segments)
	{
		i = 0;
		section = (const t_section*)segments->sections.begin;
		*seg = segments->name;
		while (i < segments->sections.nelems)
		{
			if (!ft_strcmp(section[i].name, sect))
				return (section + i);
			++i;
		}
		segments = segments->next;
	}
	return (NULL);
}

static size_t uint_size(t_type type)
{
	if (type.endian == BIG)
		return (sizeof(uint32_t));
	return (sizeof(uint8_t));
}

static uint32_t uint_value(t_type type, const uint8_t* ptr)
{
	if (type.endian == BIG)
		return (*(const uint32_t*)ptr);
	return (*ptr);
}

static uint8_t	disp_section_routine(const t_map *map, const t_section *section, t_obuff *buff)
{
	uint64_t		cursor;
	unsigned int	line_state;
	const uint8_t	*tmp;

	cursor = section->offset;
	line_state = 0;
	while (cursor < section->offset + section->size)
	{
		if (!line_state)
			add_addr_to_obuff(section->addr + cursor - section->offset,
					map->type.mtype, buff);
		if (!(tmp = safe_access(map->addr, cursor, map->size)))
			return (0);
		add_uint_to_obuff(uint_value(map->type, tmp), uint_size(map->type),
				map->type.endian, buff);
		cursor += uint_size(map->type);
		if ((line_state += (uint_size(map->type) * 8) / 4) >= 32 ||
				cursor >= section->offset + section->size)
		{
			ft_add_char_to_obuff('\n', buff);
			line_state = 0;
		}
	}
	return (1);
}

uint8_t		display_section(const t_map *map, const t_macho_data *data,
				const char *sect)
{
	const t_section *current;
	t_obuff			buff;
	const char		*seg_name;

	buff = (t_obuff) {.cursor = 0, .fd = 1};
	if (!(current = get_section_and_segname(data->segments, sect, &seg_name)))
	{
		ft_putstr_fd("Section not found\n", STDERR_FILENO);
		return (0);
	}
	ft_add_str_to_obuff("Contents of (", &buff);
	if (seg_name && *seg_name)
		ft_add_str_to_obuff(seg_name, &buff);
	else 
		ft_add_upper_str_to_obuff(sect, &buff);
	ft_add_char_to_obuff(',', &buff);
	ft_add_str_to_obuff(current->name, &buff);
	ft_add_str_to_obuff(") section\n", &buff);
	if (!disp_section_routine(map, current, &buff))
	{
		ft_putstr_fd(PARSE_ERR, STDERR_FILENO);
		return (0);
	}
	ft_flush_obuff(&buff);
	return (1);
}
