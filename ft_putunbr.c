/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:48:39 by bcili             #+#    #+#             */
/*   Updated: 2024/12/01 19:12:04 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digitcount(unsigned int x)
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

int	ft_putunbr(unsigned int x)
{
	int		digit;
	char	c;

	digit = digitcount(x);
	if (x <= 9)
	{
		c = x + '0';
		write(1, &c, 1);
	}
	else if (x > 9)
	{
		ft_putunbr(x / 10);
		ft_putunbr(x % 10);
	}
	return (digit);
}
