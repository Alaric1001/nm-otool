/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:30:46 by asenat            #+#    #+#             */
/*   Updated: 2018/09/28 17:48:14 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTURES_H
# define DATA_STRUCTURES_H

# include <stdint.h>
# include <stdlib.h>
# include <sys/stat.h>

# include "utils/typedefs.h"

typedef enum	e_mtype
{
	ARCHIVE,
	ARCHIVE64,
	MACHO,
	MACHO64,
	FAT,
	FAT64,
	NONE,
}				t_mtype;

typedef enum	e_mach_struct
{
	HEADER = 0,
	NLIST = 2,
	FAT_ARCH = 4,
}				t_mach_struct;

typedef struct 	s_file
{
	const char 	*name;
	int			fd;
	struct stat	*stats;
}				t_file;

typedef struct 	s_map
{
	size_t	size;
	uint8_t	*addr;
	void	*begin;
	t_mtype	type;
}				t_map;

#endif
