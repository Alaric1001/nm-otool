/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 11:03:09 by asenat            #+#    #+#             */
/*   Updated: 2018/10/04 15:07:48 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"
#include <stdio.h>

static uint32_t		get_nsects(const t_segcommand *cmd, const t_map *map)
{
	const t_segcommand64 *cmd64;

	if (map->type.mtype == MACHO64)
	{
		cmd64 = (const t_segcommand64*)cmd;
		return (cmd64->nsects);
	}
	return (cmd->nsects);
}

static void 		get_size_and_offset(const t_msection *sec,
			const t_map *map, uint64_t *size, uint64_t *offset)
{
	const t_msection64 *sec64;

	if (map->type.mtype == MACHO64)
	{
		sec64 = (const t_msection64*)sec;
		*size = get_uint64(sec64->size, map->type.endian);
		*offset = get_uint64(sec64->offset, map->type.endian);
		return ;
	}
	*size = get_uint64(sec->size, map->type.endian);
	*offset = get_uint64(sec->offset, map->type.endian);
}

static t_segment	*malloc_last_segment(t_segment **segments)
{
	while (*segments)
		segments = &(*segments)->next;
	*segments = ft_memalloc(sizeof(t_segment));
	return (*segments);
}

static t_section	*get_section_at(t_array *sections, uint32_t index)
{
	t_section	*array;

	array = (t_section*)sections->begin;
	return (&array[index]);
}

uint8_t				get_sections(const t_segcommand *cmd, const t_map *map,
						t_segment **segments)
{
	uint32_t			nsects;
	const t_msection	*msection;
	t_section			*section;
	t_segment			*last;
	uint32_t			i;
		
	last = malloc_last_segment(segments);
	nsects = get_uint32(get_nsects(cmd, map), map->type.endian);
	ft_memcpy(last->name, cmd->segname, 16);
	last->sections.nelems = nsects;
	last->sections.begin = ft_memalloc(sizeof(t_section) * nsects);
	if (!(msection = (const t_msection*)safe_access(cmd, 
			get_struct_size(SEGMENT_CMD, map->type.mtype), map->size)))
		return (0);
	i = 0;
	while (i < nsects)
	{
		section = get_section_at(&last->sections, i++);
		ft_memcpy(section->name, msection->sectname, 16);
		get_size_and_offset(msection, map, &section->size, &section->offset);
		if (!(msection = (const t_msection*)safe_access(msection,
			get_struct_size(SECTION, map->type.mtype), map->size)))
				return (0);
	}
	return (1);
}
