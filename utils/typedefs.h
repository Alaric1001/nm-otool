/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:15:19 by asenat            #+#    #+#             */
/*   Updated: 2018/09/27 15:57:45 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>

typedef struct mach_header_64 header64_t;
typedef struct mach_header header_t;
typedef struct load_command command_t;
typedef struct symtab_command symcommand_t;
typedef struct nlist nlist_t;
typedef struct nlist_64 nlist64_t;
typedef struct fat_header t_fat_header;
typedef struct fat_arch t_fat_arch;
typedef struct fat_arch_64 t_fat_arch64;

#endif
