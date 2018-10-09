/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:41:41 by asenat            #+#    #+#             */
/*   Updated: 2018/10/09 13:30:10 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"
#include "common/typedefs.h"

#include "libft/string/string.h"
#include "libft/lists/lists.h"

#include <ar.h>
#include <mach-o/ranlib.h>

static void		free_lst(void* content, size_t size)
{
	free(content);
	(void)size;
}

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
	h->file_size = ft_atoi(h->head->ar_size);
	return (h->file_size > 0);
}

static uint8_t	put_mach_header(const t_ar_header *hd, const t_map *orig, t_map *dst)
{
	if (!(dst->addr = (void*)safe_access(hd->head, hd->size, orig->size))) 
		return (0);
	dst->size = ft_atoi(hd->head->ar_size);
	dst->metadata.name = hd->name;
	dst->metadata.cpu = orig->metadata.cpu;
	dst->type = get_file_type(dst);
	return (1);
}

t_list	*get_headers(const t_map *map)
{
	t_list	*ret;
	t_ar_header hd;
	uint32_t total;

	if (!get_head(map, SARMAG, &hd))
		return (NULL);
	if (ft_strncmp(hd.name, SYMDEF, 9) &&
			ft_strncmp(hd.name, SYMDEF_SORTED, 16))
		return (NULL);
	ret = NULL;
	total = SARMAG + sizeof(*hd.head) + hd.file_size;
	while (total < map->size && get_head(map, total, &hd))
	{
		ft_lstadd_back(&ret, &hd, sizeof(t_ar_header));
		total += sizeof(*hd.head) + hd.file_size;
	}
	return (ret);
}

uint8_t	split_arch(const t_map *map, t_array *maps)
{
	t_list				*headers;
	const t_list		*cursor;
	uint32_t			len;
	const t_ar_header	*hdr;
	uint32_t			i;

	if (!(headers = get_headers(map)))
		return (0);
	len = ft_lstlen(headers);
	maps->begin = ft_memalloc(len * sizeof(t_map));
	maps->nelems = len;
	cursor = headers;
	i = 0;
	while (cursor)
	{
		hdr = (const t_ar_header*)cursor->content;
		if (!put_mach_header(hdr, map, &((t_map*)maps->begin)[i++]))
			break ;
		cursor = cursor->next;
	}
	ft_lstdel(&headers, free_lst);
	return (i == len);
}
