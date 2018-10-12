/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 11:03:09 by asenat            #+#    #+#             */
/*   Updated: 2018/10/12 14:46:59 by asenat           ###   ########.fr       */
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

static void			get_section_data(const t_msection *sec,
			const t_map *map, t_section *sect)
{
	const t_msection64 *sec64;

	if (map->type.mtype == MACHO64)
	{
		sec64 = (const t_msection64*)sec;
		sect->addr = get_uint64(sec64->addr, map->type.endian);
		sect->size = get_uint64(sec64->size, map->type.endian);
		sect->offset = get_uint64(sec64->offset, map->type.endian);
		return ;
	}
	sect->addr = get_uint32(sec->addr, map->type.endian);
	sect->size = get_uint32(sec->size, map->type.endian);
	sect->offset = get_uint32(sec->offset, map->type.endian);
}

static t_segment	*malloc_last_segment(const t_segcommand *cmd, const t_map *map,
						t_segment **segments)
{
	const t_segcommand64 *cmd64;

	while (*segments)
		segments = &(*segments)->next;
	*segments = ft_memalloc(sizeof(t_segment));
	ft_memcpy((*segments)->name, cmd->segname, 16);
	if (map->type.mtype == MACHO64)
	{
		cmd64 = (const t_segcommand64*)cmd;
		(*segments)->vmaddr = get_uint64(cmd64->vmaddr, map->type.endian);
		(*segments)->vmsize = get_uint64(cmd64->vmsize, map->type.endian);
		(*segments)->foffset = get_uint64(cmd64->fileoff, map->type.endian);
		(*segments)->fsize = get_uint64(cmd64->filesize, map->type.endian);
	}
	(*segments)->vmaddr = get_uint32(cmd->vmaddr, map->type.endian);
	(*segments)->vmsize = get_uint32(cmd->vmsize, map->type.endian);
	(*segments)->foffset = get_uint32(cmd->fileoff, map->type.endian);
	(*segments)->fsize = get_uint32(cmd->filesize, map->type.endian);
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

	last = malloc_last_segment(cmd, map, segments);
	nsects = get_uint32(get_nsects(cmd, map), map->type.endian);
	last->sections.nelems = get_uint32(get_nsects(cmd, map),
			map->type.endian);
	last->sections.begin = ft_memalloc(sizeof(t_section) * nsects);
	if (!(msection = (const t_msection*)safe_access(cmd,
			get_struct_size(SEGMENT_CMD, map->type.mtype), map->size)))
		return (0);
	i = 0;
	while (i < nsects)
	{
		section = get_section_at(&last->sections, i++);
		ft_memcpy(section->name, msection->sectname, 16);
		get_section_data(msection, map, section);
		if (!(msection = (const t_msection*)safe_access(msection,
			get_struct_size(SECTION, map->type.mtype), map->size)))
			return (0);
	}
	return (1);
}
