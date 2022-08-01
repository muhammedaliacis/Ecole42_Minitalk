/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macis <macis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:34:45 by macis             #+#    #+#             */
/*   Updated: 2022/07/03 15:31:41 by macis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
			return (ft_convert(2147483648, "0123456789") + 1);
		return (ft_convert(-n, "0123456789") + 1);
	}
	return (ft_convert(n, "0123456789"));
}

int	ft_convert(size_t i, char *taban)
{
	int				len;
	char			*nb;
	static char		str[50];

	len = ft_strlen(taban);
	nb = &str[49];
	*nb-- = '\0';
	*nb = taban[i % len];
	i /= len;
	while (i)
	{
		*--nb = taban[i % len];
		i /= len;
	}
	return (ft_putstr(nb));
}
