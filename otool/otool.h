/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:19:10 by asenat            #+#    #+#             */
/*   Updated: 2018/10/10 18:22:01 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_H
# define OTOOL_H

# include "opt/opt.h"

# define OPT_TEXT 0x2
t_opt		otool_opt_parser(t_opt curr_opt, const char *arg);

#endif
