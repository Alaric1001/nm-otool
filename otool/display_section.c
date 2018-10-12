/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_section.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 14:09:44 by asenat            #+#    #+#             */
/*   Updated: 2018/10/12 17:42:32 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool/otool.h"

#include "common/common.h"
#include "libft/string/string.h"
#include "libft/output/output.h"
#include "libft/output/obuff.h"
#include "libft/math/math.h"

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

static void		add_uint_to_obuff(uint32_t nb, size_t size, t_obuff* obuff)
{
	size_t	nb_len;
	int		padding;

	nb_len = ft_get_u_nb_len(nb, 16) + 1;
	if (size == sizeof(uint8_t))
		padding = (sizeof(uint8_t) * 8 / 4) - nb_len;
	else
		padding = (sizeof(uint32_t) * 8 / 4) - nb_len;
	while (padding-- > 0)
		ft_add_char_to_obuff('0', obuff);
	ft_add_uint_base_to_obuff(nb, LIBFT_FMT_HEX, obuff);
	ft_add_char_to_obuff(' ', obuff);
}

static void		add_addr_to_obuff(uint64_t addr, t_mtype mtype, t_obuff* obuff)
{
	size_t	addr_len;
	int		padding;

	addr_len = ft_get_u_nb_len(addr, 16) + 1;
	if (mtype == MACHO64)
		padding = 16 - addr_len;
	else
		padding = 8 - addr_len;
	while (padding-- > 0)
		ft_add_char_to_obuff('0', obuff);
	ft_add_uint_base_to_obuff(addr, LIBFT_FMT_HEX, obuff);
	ft_add_char_to_obuff('\t', obuff);
} 

static uint8_t	disp_section_routine(const t_map *map, const t_section *section, t_obuff *buff)
{
	uint64_t		cursor;
	unsigned int	line_state;
	const uint8_t	*tmp;

	cursor = section->offset;
	line_state = 0;
	add_addr_to_obuff(section->addr, map->type.mtype, buff);
	while (cursor < section->offset + section->size)
	{
		if (!(tmp = safe_access(map->addr, cursor, map->size)))
			return (0);
		add_uint_to_obuff(*tmp, sizeof(uint8_t), buff);
		cursor += sizeof(uint8_t);
		if ((line_state += (sizeof(uint8_t) * 8) / 4) >= 32 &&
				cursor < section->offset + section->size)
		{
			ft_add_char_to_obuff('\n', buff);
			add_addr_to_obuff(section->addr + cursor - section->offset, map->type.mtype, buff);
			line_state = 0;
		}
	}
	ft_add_char_to_obuff('\n', buff);
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
	ft_add_str_to_obuff(seg_name, &buff);
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
