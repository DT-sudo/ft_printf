/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtereshc <dtereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:12:51 by dtereshc          #+#    #+#             */
/*   Updated: 2024/11/03 21:11:11 by dtereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sgn_type(const char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += print_char(va_arg(args, int));
	else if (format == 'd' || format == 'i')
		len += print_int(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		len += print_hex(va_arg(args, unsigned int), format);
	else if (format == 'u')
		len += print_unsigned(va_arg(args, unsigned int));
	else if (format == 'p')
		len += print_pointer(va_arg(args, void *));
	else if (format == 's')
		len += print_string(va_arg(args, char *));
	else if (format == '%')
		len += print_char(format);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(++format))
			len += sgn_type(*format++, args);
		else
		{
			ft_putchar_fd(*format++, 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}

// a = 4294967295;
// int	main(void)
// {
// 	// int value = 42;
// 	// int *ptr = &value;
// 	int len;
// 	char *aa;
// 	aa = NULL;
// 	// ft_printf("The actual str: qwe\n");
// 	// ft_printf("The int: %i\n", 21);
// 	// ft_printf("The dint: %d\n", 23);
// 	// ft_printf("The char: %c\n", 'A');
// 	// ft_printf("The string: %s\n", "str");
// 	// ft_printf("The ptr: \n%p\n", ptr);
// 	// printf("%p", ptr);
// 	// len = ft_printf("qwe, %i, %d, %c, %s, %p %%.%c.", 1, 2, 'A', "str", ptr,
// 	// 		'a');
// 	// printf("\n%d", len);
// 	// printf("%u", -1);
// 	// printf("NULL %s NULL", (char*)NULL);
// 	len = ft_printf("NULL %s NULL", aa);
// 	printf("%d", len);
// 	return (0);
// }