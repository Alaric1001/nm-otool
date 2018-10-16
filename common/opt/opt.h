/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:28:29 by asenat            #+#    #+#             */
/*   Updated: 2018/10/10 18:49:20 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPT_H
# define OPT_H

# include <stdint.h>

# define OPT_ERR	(t_opt)-1
# define OPT_FILE	0x1

typedef struct		s_args
{
	uint32_t	count;
	const char	**args;
}					t_args;

typedef uint32_t	t_opt;

t_opt				parse_options(const t_args *args, const char **files[],
						t_opt (*opt_parser)(t_opt opt, const char *arg));
uint8_t				has_option(t_opt opt, uint32_t option);

#endif
