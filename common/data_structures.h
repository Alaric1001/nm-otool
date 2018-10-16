/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:30:46 by asenat            #+#    #+#             */
/*   Updated: 2018/10/16 10:54:09 by asenat           ###   ########.fr       */
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

typedef enum	e_endianness
{
	LITTLE,
	BIG,
}				t_endianness;

typedef struct	s_type
{
	t_mtype			mtype;
	t_endianness	endian;
}				t_type;

typedef struct	s_file
{
	const char	*name;
	int			fd;
	struct stat	*stats;
}				t_file;

typedef struct	s_map_metadata
{
	cpu_type_t	cpu;
	const char	*name;
}				t_map_metadata;

typedef struct	s_map
{
	size_t			size;
	uint8_t			*addr;
	t_type			type;
	t_map_metadata	metadata;
}				t_map;

typedef struct	s_segments
{
	t_array				sections;
	char				name[16];
	uint64_t			foffset;
	uint64_t			fsize;
	struct s_segments	*next;
}				t_segment;

typedef struct	s_section
{
	char		name[16];
	uint64_t	addr;
	uint64_t	size;
	uint64_t	offset;
}				t_section;

typedef struct	s_symbol
{
	const char		*name;
	const t_nlist	*nlist;
	uint64_t		value;
}				t_symbol;

typedef struct	s_macho_data
{
	t_array		*symbols;
	t_segment	*segments;
}				t_macho_data;

typedef struct	s_ar_header
{
	const struct ar_hdr	*head;
	const char			*name;
	size_t				size;
	size_t				file_size;
}				t_ar_header;

#endif
