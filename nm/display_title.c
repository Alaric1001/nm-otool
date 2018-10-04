/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_title.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:35:36 by asenat            #+#    #+#             */
/*   Updated: 2018/10/04 18:07:29 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm/nm.h"

#include <mach/machine.h>

static void add_cpu_type(cpu_type_t cputype, t_obuff *obuff)
{
	static const cpu_type_t types[] = {CPU_TYPE_MC680x0, CPU_TYPE_I386,
		CPU_TYPE_MC98000, CPU_TYPE_HPPA, CPU_TYPE_ARM, CPU_TYPE_ARM64,
		CPU_TYPE_MC88000, CPU_TYPE_SPARC, CPU_TYPE_I860, CPU_TYPE_POWERPC,
		CPU_TYPE_POWERPC64, 0};
	static const char		*names[] = {"mc680", "i386", "mc98k", "hppa",
		"arm", "arm64", "mc88k", "sparc", "i860", "ppc", "ppc64", "unknown"};
	size_t					i;

	i = 0;
	while (types[i])
	{
		if (types[i] == cputype)
			break;
		++i;
	}
	ft_add_str_to_obuff(names[i], obuff);
}

void	display_title(const char *fname, cpu_type_t cputype)
{
	t_obuff			obuff;

	(void)cputype;
	obuff = (t_obuff){.cursor = 0, .fd = 1};
	ft_add_str_to_obuff(fname, &obuff);
	if (cputype != CPU_TYPE_X86 && cputype != CPU_TYPE_X86_64)
	{
		ft_add_str_to_obuff(" (for architecture ", &obuff);
		add_cpu_type(cputype, &obuff);
		ft_add_char_to_obuff(')', &obuff);
	}
	ft_add_str_to_obuff(":\n", &obuff);
	ft_flush_obuff(&obuff);
}
