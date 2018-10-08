/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 10:41:58 by asenat            #+#    #+#             */
/*   Updated: 2018/10/05 14:58:33 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"
#include "common/typedefs.h"

#include "libft/memory/memory.h"

#include <mach-o/fat.h>
#include <ar.h>

t_type	get_file_type(const t_map *map)
{
	static const long	identifiers[] = {MH_MAGIC, MH_MAGIC_64, FAT_MAGIC,
		FAT_MAGIC_64, 0};
	const t_header		*head;
	int					i;

	if (!ft_memcmp(map->addr, ARMAG, SARMAG))
		return ((t_type){ARCHIVE, LITTLE});
	head = (t_header*)map->addr;
	if (map->size <= sizeof(t_header))
		return ((t_type){NONE, LITTLE});
	i = -1;
	while (identifiers[++i])
	{
		if (head->magic == identifiers[i])
			return ((t_type){MACHO + i, LITTLE});
		if (head->magic == get_uint32(identifiers[i], BIG))
			return ((t_type){MACHO + i, BIG});
	}
	return ((t_type){NONE, LITTLE});
}
