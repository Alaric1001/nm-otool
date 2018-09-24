/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:30:35 by asenat            #+#    #+#             */
/*   Updated: 2018/09/24 18:32:22 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/stat.h>
# include <stdint.h>

typedef struct 	s_file
{
	const char 	*name;
	int			fd;
	struct stat	*stats;
}				t_file;

uint8_t	open_file(const char *filename, int oflags, t_file *file);
void	close_file(t_file *file);

#endif
