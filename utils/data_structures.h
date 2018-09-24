/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:30:46 by asenat            #+#    #+#             */
/*   Updated: 2018/09/24 19:35:53 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTURES_H
# define DATA_STRUCTURES_H

# include <sys/stat.h>
# include <stdlib.h>

typedef struct 	s_file
{
	const char 	*name;
	int			fd;
	struct stat	*stats;
}				t_file;

typedef struct 	s_map
{
	size_t	size;
	void	*addr;
}				t_map;

#endif
