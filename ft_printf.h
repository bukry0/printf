/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:11:19 by bcili             #+#    #+#             */
/*   Updated: 2024/12/02 18:18:31 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(int c);
int	ft_puthex(unsigned int x, char c);
int	ft_putnbr(int x);
int	ft_putptr(unsigned long x);
int	ft_putstr(char *s);
int	ft_putunbr(unsigned int x);
int	ft_sorting(const char c, va_list args);

#endif