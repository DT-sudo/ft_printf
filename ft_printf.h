/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtereshc <dtereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:57:03 by dtereshc          #+#    #+#             */
/*   Updated: 2024/11/03 20:42:04 by dtereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		print_char(const char c);
int		print_int(int nb);
int		print_hex(unsigned int num, const char format);
int		print_string(char *str);
int		print_pointer(void *ptr);
int		print_unsigned(unsigned int a);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *wrd);
#endif