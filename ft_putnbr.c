/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:02:02 by bcili             #+#    #+#             */
/*   Updated: 2024/12/01 19:11:54 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digitcount(int x)
{
	int	digit;

	digit = 0;
	while (x != 0)
	{
		x /= 10;
		digit++;
	}
	return (digit);
}

int	ft_putnbr(int x)
{
	int		len;
	char	c;

	len = digitcount(x);
	if (x == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (x < 0)
	{
		write (1, "-", 1);
		x *= -1;
		len++;
	}
	c = x + '0';
	if (x <= 9 && x >= 0)
		write(1, &c, 1);
	else if (x > 9)
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
	return (len);
}
