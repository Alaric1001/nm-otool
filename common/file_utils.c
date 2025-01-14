/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:47:46 by asenat            #+#    #+#             */
/*   Updated: 2018/10/10 14:40:08 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/common.h"

#include "libft/output/output.h"

#include <fcntl.h>
#include <unistd.h>

uint8_t		open_file(const char *filename, int oflags, t_file *file)
{
	if ((file->fd = open(filename, oflags)) == -1)
	{
		ft_file_error(filename, "Can't open file");
		return (0);
	}
	file->stats = ft_memalloc(sizeof(struct stat));
	if ((fstat(file->fd, file->stats)) == -1)
	{
		ft_file_error(filename, "Can't retrieve stats");
		close_file(file);
		return (0);
	}
	if (!(file->stats->st_mode & S_IFREG))
	{
		ft_file_error(filename, "Not a regular file");
		close_file(file);
		return (0);
	}
	file->name = filename;
	return (1);
}

void		close_file(t_file *file)
{
	free(file->stats);
	if (close(file->fd) == -1)
		ft_file_error(file->name, "An error occured while closing the file");
}
