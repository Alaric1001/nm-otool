/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:09:52 by asenat            #+#    #+#             */
/*   Updated: 2018/10/10 14:40:38 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"
#include "common/typedefs.h"

size_t	get_struct_size(t_mach_struct stype, t_mtype mtype)
{
	static const size_t sizes[] = {sizeof(t_header), sizeof(t_header64),
								sizeof(t_nlist), sizeof(t_nlist64),
								sizeof(t_fat_arch), sizeof(t_fat_arch64),
								sizeof(t_segcommand), sizeof(t_segcommand64),
								sizeof(t_msection), sizeof(t_msection64)};

	return (sizes[stype + mtype % 2]);
}
