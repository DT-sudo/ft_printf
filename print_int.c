/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtereshc <dtereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:11:25 by dtereshc          #+#    #+#             */
/*   Updated: 2024/11/03 20:14:33 by dtereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int nb)
{
	char	i;
	int		len;

	len = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		len += 1;
	}
	if (nb > 9)
	{
		len += print_int(nb / 10);
	}
	i = nb % 10 + '0';
	write(1, &i, 1);
	len += 1;
	return (len);
}

// int	main(void)
// {
//     int aa = 12900;

// 	print_
// 	printf("\n%d", aa);
// 	return (0);
// }