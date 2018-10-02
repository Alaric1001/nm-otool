/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:15:19 by asenat            #+#    #+#             */
/*   Updated: 2018/10/01 12:00:17 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>

typedef struct mach_header_64 t_header64;
typedef struct mach_header t_header;
typedef struct load_command t_command;
typedef struct segment_command t_segcommand;
typedef struct segment_command_64 t_segcommand64;
typedef struct symtab_command t_symcommand;
typedef struct nlist t_nlist;
typedef struct nlist_64 t_nlist64;
typedef struct fat_header t_fat_header;
typedef struct fat_arch t_fat_arch;
typedef struct fat_arch_64 t_fat_arch64;
typedef struct section t_msection;
typedef struct section_64 t_msection64;

#endif
