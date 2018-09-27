/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:09:52 by asenat            #+#    #+#             */
/*   Updated: 2018/09/27 15:59:41 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "utils/typedefs.h"

size_t	get_struct_size(t_mach_struct stype, t_mtype mtype)
{
	static const size_t sizes[] = {sizeof(header_t), sizeof(header64_t),
									sizeof(nlist_t), sizeof(nlist64_t),
									sizeof(t_fat_arch), sizeof(t_fat_arch64)};
	return (sizes[stype + mtype % 2]);
}
