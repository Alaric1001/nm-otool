/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symbols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:51:01 by asenat            #+#    #+#             */
/*   Updated: 2018/10/01 15:21:51 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm/nm.h"
#include "utils/utils.h"

static void	add_symbol(t_symbol *symbols, const char* sym_tab,
		const t_nlist *nlist, const t_map *map)
{
	const t_nlist64* nlist64;
	
	symbols->name = sym_tab + nlist->n_un.n_strx;
	symbols->nlist = nlist;
	if (map->type == MACHO64)
	{
		nlist64 = (const t_nlist64*)nlist;
		symbols->value = nlist64->n_value;
	}
	else
		symbols->value = nlist->n_value;
}

static void	realloc_symbols(const t_symbol* new_symbols, t_array *symbols)
{
	size_t 		new_len;
	t_symbol	*symbols_ptr;

	new_len = 0;
	while (new_symbols[new_len].nlist)
		++new_len;
	symbols->begin = ft_realloc(symbols->begin,
			symbols->nelems	* sizeof(t_symbol),
			(symbols->nelems + new_len) * sizeof(t_symbol));
	symbols_ptr = (t_symbol*)symbols->begin;
	ft_memcpy(symbols_ptr + symbols->nelems, new_symbols,
			new_len * sizeof(t_symbol));
	symbols->nelems += new_len;
}

static uint8_t	get_static_symbols_routine(const t_symcommand *cmd,
		const t_map *map, t_symbol new_symbols[], const char *s_table)
{
	uint32_t		i;
	int				symbol_i;
	size_t			shift;
	const t_nlist	*nlist;

	shift = cmd->symoff;
	i = 0;
	symbol_i = 0;
	while (i < cmd->nsyms)
	{
		if (!(nlist = (const t_nlist*)safe_access(map->addr, shift, map->size)))
			return (0);
		if (!(nlist->n_type & N_STAB))
			add_symbol(&new_symbols[symbol_i++], s_table, nlist, map);
		shift += get_struct_size(NLIST, map->type);
		++i;
	}
	return (1);
}

uint8_t		get_static_symbols(const t_symcommand *cmd, const t_map *map,
						t_array *symbols)
{
	const char		*s_table;
	t_symbol		new_symbols[cmd->nsyms + 1];

	if (!(s_table = (const char*)safe_access(map->addr, cmd->stroff,
					map->size)))
		return (0);
	ft_bzero(new_symbols, (cmd->nsyms + 1) * sizeof(t_symbol));
	if (!get_static_symbols_routine(cmd, map, new_symbols, s_table))
		return (0);
	realloc_symbols(new_symbols, symbols);
	return (1);
}
