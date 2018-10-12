/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_different_cpu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:02:37 by asenat            #+#    #+#             */
/*   Updated: 2018/10/11 11:03:13 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"

uint8_t		has_different_cpus(const t_array *maps)
{
	const t_map		*first_map;
	uint32_t		i;
	cpu_type_t		last_cpu;

	first_map = (const t_map*)maps->begin;
	last_cpu = first_map->metadata.cpu;
	i = 1;
	while (i < maps->nelems)
	{
		if (first_map[i].metadata.cpu != last_cpu)
			return (1);
		last_cpu = first_map[i++].metadata.cpu;
	}
	return (0);
}

