/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macis <macis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:34:37 by macis             #+#    #+#             */
/*   Updated: 2022/07/03 18:27:40 by macis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_write(char c, va_list params)
{
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'c')
		return (ft_putchar(va_arg(params, int)));
	if (c == 's')
		return (ft_putstr(va_arg(params, char *)));
	if (c == 'p')
	{
		ft_putstr("0x");
		return (ft_convert(
				va_arg(params, unsigned long), "0123456789abcdef") + 2);
	}
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(params, int)));
	if (c == 'u')
		return (ft_convert(va_arg(params, unsigned int), "0123456789"));
	if (c == 'x')
		return (ft_convert(va_arg(params, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_convert(va_arg(params, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	macro;
	int		a;
	int		b;

	va_start(macro, str);
	a = 0;
	b = 0;
	while (str[a])
	{
		if (str[a] == '%')
		{
			b += printf_write(str[a + 1], macro);
			a++;
		}
		else
			b += write(1, &str[a], 1);
		a++;
	}
	va_end(macro);
	return (b);
}
