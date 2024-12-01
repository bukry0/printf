/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:41:48 by bcili             #+#    #+#             */
/*   Updated: 2024/12/01 19:12:07 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sorting(const char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (c == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		len = ft_putptr(va_arg(args, unsigned long long int));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len = ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len = ft_puthex(va_arg(args, unsigned long long int), c);
	else if (c == '%')
	{
		write(1, "%", 1);
		len = 1;
	}
	else
		return (-1);
	return (len);
}
