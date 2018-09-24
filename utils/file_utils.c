/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:47:46 by asenat            #+#    #+#             */
/*   Updated: 2018/09/24 16:38:03 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

#include "libft/memory/memory.h"
#include "libft/output/obuff.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

static void		file_error(const char *filename, const char *err)
{
	t_obuff buff;

	buff = (t_obuff){.cursor = 0, .fd = 2};
	ft_add_str_to_obuff(filename, &buff);
	ft_add_str_to_obuff(": ", &buff);
	ft_add_str_to_obuff(err, &buff);
	ft_add_str_to_obuff(" [errcode '", &buff);
	ft_add_uint_to_obuff(errno, &buff);
	ft_add_str_to_obuff("']\n", &buff);
	ft_flush_obuff(&buff);
}

int				open_file(const char* filename, int oflags, t_file *file)
{
	if ((file->fd = open(filename, oflags)) == -1)
	{
		file_error(filename, "Can't open file");
		return (0);
	}
	file->stats = ft_memalloc(sizeof(struct stat));
	if ((fstat(file->fd, file->stats)) == -1)
	{
		file_error(filename, "Can't retrieve stats");
		close_file(file);
		return (0);
	}
	if (!(file->stats->st_mode & S_IFREG))
	{
		file_error(filename, "Not a regular file");
		close_file(file);
		return (0);
	}
	file->name = filename;
	return (1);
}

void		close_file(t_file* file)
{
	free(file->stats);
	if (close(file->fd) == -1)
		file_error(file->name, "An error occured while closing the file");
}
