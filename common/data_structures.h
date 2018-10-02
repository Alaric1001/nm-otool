/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:30:46 by asenat            #+#    #+#             */
/*   Updated: 2018/10/01 13:00:01 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTURES_H
# define DATA_STRUCTURES_H

# include "common/typedefs.h"

# include "libft/memory/memory.h"

# include <stdint.h>
# include <stdlib.h>
# include <sys/stat.h>

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
	SEGMENT_CMD = 6,
	SECTION = 8,
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

typedef struct	s_segments
{
	t_array				sections;
	char				name[16];
	struct s_segments	*next;
}				t_segment;

typedef struct s_section
{
	char		name[16];
	uint64_t	size;
	uint64_t	offset;
}				t_section;

#endif
