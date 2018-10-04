/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 10:41:58 by asenat            #+#    #+#             */
/*   Updated: 2018/10/03 19:10:51 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"
#include "common/typedefs.h"

#include "libft/memory/memory.h"

#include <mach-o/fat.h>

t_mtype	get_file_type(const t_map *map)
{
	static const long	identifiers[] = {MH_MAGIC, MH_MAGIC_64, FAT_CIGAM,
		FAT_CIGAM_64, 0};
	const t_header		*head;
	int					i;

	if (!ft_memcmp(map->addr, "<!arch>\n", 8))
		return (ARCHIVE);
	head = (t_header*)map->addr;
	if (map->size <= sizeof(t_header))
		return (NONE);
	i = -1;
	while (identifiers[++i])
		if (head->magic == identifiers[i])
			return (MACHO + i);
	return (NONE);
}
