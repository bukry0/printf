/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:58:15 by bcili             #+#    #+#             */
/*   Updated: 2024/12/02 14:19:57 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digitcounthex(unsigned long x)
{
	int	digit;

	digit = 0;
	while (x > 0)
	{
		x /= 16;
		digit++;
	}
	return (digit);
}

int	ft_puthex(unsigned long x, char c)
{
	char	ch;

	ch = '\0';
	if (x < 16)
	{
		if (x <= 9)
			ch = x + '0';
		else
		{
			if (c == 'x')
				ch = x - 10 + 'a';
			else
				ch = x - 10 + 'A';
		}
		write(1, &ch, 1);
	}
	else
	{
		ft_puthex(x / 16, c);
		ft_puthex(x % 16, c);
	}
	return (digitcounthex(x));
}
