/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtereshc <dtereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:11:36 by dtereshc          #+#    #+#             */
/*   Updated: 2024/11/03 20:49:48 by dtereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int a)
{
	char	i;
	int		len;

	len = 0;
	if (a < 0)
	{
		a = 4294967296 - (a * -1);
	}
	if (a >= 10)
	{
		len += print_unsigned(a / 10);
	}
	i = a % 10 + '0';
	write(1, &i, 1);
	len += 1;
	return (len);
}

// 4294967295
// int	main(void)
// {
// 	int a;

// 	a = 2101202;
// 	printf("%u\n", a);
// 	printf("\n%d", print_unsigned(a));

// 	return (0);
// }