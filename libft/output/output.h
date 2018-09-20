/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:59:25 by asenat            #+#    #+#             */
/*   Updated: 2018/05/26 16:34:26 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

# include <wchar.h>
# include <stdarg.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_putnstr_fd(char const *s, size_t n, int fd);
void	ft_putchar(char c);
void	ft_putnchar(char const *s, size_t n);
void	ft_putstr(char const *s);
void	ft_putendl(char const*s);
void	ft_putnbr(int n);
int		ft_putnstr(char const *s, size_t n);
void	ft_putwchar_fd(wchar_t c, int fd, size_t size);
void	ft_putwchar(wchar_t c, size_t size);
void	ft_putwstr_fd(wchar_t const *str, int fd);
void	ft_putwstr(wchar_t const *str);
int		ft_putnbyteswstr(wchar_t const *str, size_t n);
int		ft_putcolored(char const *s, char const *code, int fd);

int		ft_printf(char const *format, ...);
#endif
