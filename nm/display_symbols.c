/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_symbols.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:40:11 by asenat            #+#    #+#             */
/*   Updated: 2018/09/28 17:27:11 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm/nm.h"
#include "utils/utils.h"
#include "libft/output/obuff.h"

static uint8_t	get_macho_sym(t_opt opt, const t_map *map, t_array *symbols)
{
	const header64_t	*header;
	const command_t		*command;
	size_t				shift;
	uint32_t			i;

	header = (const header64_t*)map->addr;
	shift = get_struct_size(HEADER, map->type);
	i = 0;
	(void)opt;
	while (i <= header->ncmds)
	{
		if (!(command = (const command_t*)safe_access(map->addr, shift,
					header->sizeofcmds + get_struct_size(HEADER, map->type))))
			return (0);
		if (command->cmd == LC_SYMTAB
			&& !get_static_symbols((const symcommand_t*)command, map, symbols))
		{
			free_symbols(symbols);
			return (0);
		}
		shift += command->cmdsize;
		++i;
	}
	return (1);
}

static void		display_symbols(t_opt opt, const t_array *symbols, t_mtype mtype)
{
	size_t			i;
	t_obuff			obuff;
	const t_symbol	*sym;

	i = 0;
	(void)opt;
	obuff = (t_obuff){.cursor = 0, .fd = 1};
	while (i < symbols->nelems)
	{
		sym = (const t_symbol*)symbols->begin + i;
		if (sym->name)
		{

			add_value_to_obuff(sym->value, mtype, &obuff);
			ft_add_char_to_obuff(' ', &obuff);
			add_type_to_obuff(sym->nlist, &obuff);
			ft_add_char_to_obuff(' ', &obuff);
			ft_add_str_to_obuff(sym->name, &obuff);
			ft_add_char_to_obuff('\n', &obuff);
		}
		++i;
	}
	ft_flush_obuff(&obuff);
}

uint8_t			get_and_display_symbols(t_opt opt, const t_map *map)
{
	t_array	symbols;

	(void)opt;
	symbols = (t_array){0, 0};
	if (map->type == NONE)
		return (0);
//	if (map->type == ARCHIVE)
//		return (display_arch_sym(opt, map));
	if (!get_macho_sym(opt, map, &symbols))
		return (0);
	display_symbols(opt, &symbols, map->type);
	return (1);
}
