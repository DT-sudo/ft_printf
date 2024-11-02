/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtereshc <dtereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:11:28 by dtereshc          #+#    #+#             */
/*   Updated: 2024/11/03 20:45:48 by dtereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexd(unsigned long num)
{
	const char	*hex_digits;
	char		hex[16];
	int			i;

	hex_digits = "0123456789abcdef";
	if (num == 0)
	{
		write(1, "0", 1);
		return ;
	}
	i = 0;
	while (num > 0)
	{
		hex[i++] = hex_digits[num % 16];
		num /= 16;
	}
	while (--i >= 0)
		write(1, &hex[i], 1);
}

int	hex_digit_count(unsigned long num)
{
	int	count;

	count = 1;
	while (num >= 16)
	{
		num /= 16;
		count++;
	}
	return (count);
}

int	print_pointer(void *ptr)
{
	int	printed_chars;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	printed_chars = 2;
	print_hexd((unsigned long)ptr);
	printed_chars += hex_digit_count((unsigned long)ptr);
	return (printed_chars);
}

// int main() {
//     // int evalue = 4;
//     // int *ptr = &evalue;
// 	// int len;

//     // len = print_pointer(ptr); // Print the address of ptr

// 	// printf("\n%p", ptr);
//     // printf("\n%d",len);
// 	print_pointer(ULLONG_MAX);
// 	ft_printf("%p", ULONG_MAX);
// 	return (0);
// }
