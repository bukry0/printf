/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:07:45 by bcili             #+#    #+#             */
/*   Updated: 2024/12/02 13:36:45 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	int		resofs;
	va_list	args;

	va_start(args, s);
	i = 0;
	len = 0;
	while (s[i] && i++ >= 0)
	{
		if (s[i - 1] == '%' && i++ != -1)
		{
			resofs = ft_sorting(s[i - 1], args);
			if (resofs == -1)
				return (0);
			len += resofs;
		}
		else
		{
			write(1, &s[i - 1], 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}
