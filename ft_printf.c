/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcili <bcili@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:07:45 by bcili             #+#    #+#             */
/*   Updated: 2024/12/01 19:11:46 by bcili            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	int		rofs;
	va_list	args;

	va_start(args, s);
	i = 0;
	len = 0;
	while (s[i] && i++ >= 0)
	{
		if (s[i - 1] == '%' && i++ != -1)
		{
			rofs = ft_sorting(s[i - 1], args);
			if (rofs == -1)
				break ;
			len += rofs;
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
