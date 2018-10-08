/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:41:41 by asenat            #+#    #+#             */
/*   Updated: 2018/10/08 16:48:30 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"
#include "common/typedefs.h"

#include "libft/string/string.h"

#include <ar.h>
#include <mach-o/ranlib.h>

static uint8_t  get_head(const t_map *map, uint32_t offset, t_ar_header *h)
{

	if (!(h->head = (const struct ar_hdr*)safe_access(map->addr, offset,
			map->size)))
		return (0);
	h->size = sizeof(*h->head);
	if (ft_strncmp(h->head->ar_name, AR_EFMT1, 3))
		h->name = h->head->ar_name;
	else
	{
		if (!(h->name = safe_access(h->head, h->size,
						map->size - offset)))
			return (0);
		h->size += ft_atoi(h->head->ar_name + 3);
	}
	return (1);
}

static const t_ranlib *get_ranlib(const t_map *map, uint32_t *ranlibsize)
{
	size_t 				symdeflen;
	t_ar_header			hdr;

	if (!get_head(map, SARMAG, &hdr))
		return (NULL);
	symdeflen = ft_strlen(hdr.name);
	if (ft_strncmp(hdr.name, SYMDEF, 9) &&
			ft_strncmp(hdr.name, SYMDEF_SORTED, 16))
		return (NULL);
	if (!safe_access(hdr.head, hdr.size,
				map->size - SARMAG - hdr.size))
		return (NULL);
	else
		*ranlibsize = *(uint32_t*)((const char*)hdr.head + hdr.size);
	return (safe_access(hdr.head, hdr.size + sizeof(uint32_t),
				map->size - SARMAG - hdr.size));
}

static void alloc_and_sort_ranlibs(const t_ranlib *raw,
		uint32_t ranlibsize, t_array *arr)
{
	const t_ranlib *last;
	uint32_t		i;

	arr->begin = ft_memalloc(ranlibsize * sizeof(t_ranlib*));
	last = NULL;
	i = 0;
	arr->nelems = 0;
	ranlibsize /= sizeof(t_ranlib);
	while (i < ranlibsize)
	{
		if (!last || (last && last->ran_off != raw[i].ran_off))
			((t_ranlib*)arr->begin)[arr->nelems++] = raw[i];
		last = &raw[i++];
	}

	//TODO Sort with offsets
}

static uint8_t	put_mach_header(const t_ar_header *hd, const t_ranlib *rlib, 
		const t_map *orig, t_map *dst)
{
	if (!(dst->addr = (void*)safe_access(orig->addr, rlib->ran_off + hd->size,
					orig->size))) 
		return (0);
	dst->size = ft_atoi(hd->head->ar_size);
	dst->metadata.name = hd->name;
	dst->metadata.cpu = orig->metadata.cpu;
	dst->type = get_file_type(dst);
	return (1);
}

#include <stdio.h>

uint8_t	split_arch(const t_map *map, t_array *maps)
{
	uint32_t		ranlibsize;
	const t_ranlib	*ranlibs;
	uint32_t		i;
	t_ar_header		hdr;
	t_array			arr;

	if (!(ranlibs = get_ranlib(map, &ranlibsize)))
		return (0);
	i = 0;
	alloc_and_sort_ranlibs(ranlibs, ranlibsize, &arr);
	maps->begin = ft_memalloc(arr.nelems * sizeof(t_map));
	maps->nelems = arr.nelems;
	while (i < arr.nelems)
	{
		ranlibs = &((const t_ranlib*)arr.begin)[i];
		if (!get_head(map, ranlibs->ran_off, &hdr))
			break ;
		if (!put_mach_header(&hdr, ranlibs, map,
					&((t_map*)maps->begin)[i++]))
			break ;
	}
	free(arr.begin);
	return (i == arr.nelems);
}
