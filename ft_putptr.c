/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:53:09 by bcili             #+#    #+#             */
/*   Updated: 2024/12/02 18:55:29 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digitcounthex(unsigned long x)
{
	int	digit;

	digit = 0;
	if (x == 0)
		return (1);
	while (x > 0)
	{
		x /= 16;
		digit++;
	}
	return (digit);
}

static int	ft_puthex2(unsigned long x)
{
	char	ch;

	ch = '\0';
	if (x < 16)
	{
		if (x <= 9)
			ch = x + '0';
		else
			ch = x - 10 + 'a';
		write(1, &ch, 1);
	}
	else
	{
		ft_puthex2(x / 16);
		ft_puthex2(x % 16);
	}
	return (digitcounthex(x));
}

int	ft_putptr(unsigned long x)
{
	int	len;

	len = 0;
	if (x == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		len = 2;
		len += ft_puthex2(x);
	}
	return (len);
}
