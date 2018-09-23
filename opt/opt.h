/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:28:29 by asenat            #+#    #+#             */
/*   Updated: 2018/09/20 18:37:21 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPT_H
# define OPT_H

# include <stdint.h>

# define OPT_ERR	0x0
# define OPT_FILE	0x1

typedef struct	s_args
{
	uint32_t	count;
	const char	*args[];
}				t_args;

typedef uint32_t t_opt;

t_opt	parse_options(const t_args *args, const char *files[]);

#endif