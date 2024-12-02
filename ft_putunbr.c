/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:48:39 by bcili             #+#    #+#             */
/*   Updated: 2024/12/02 15:58:44 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digitcount(unsigned int x)
{
	int	digit;

	digit = 0;
	if (x == 0)
		return (1);
	while (x > 0)
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
	else
	{
		ft_putunbr(x / 10);
		ft_putunbr(x % 10);
	}
	return (digit);
}
