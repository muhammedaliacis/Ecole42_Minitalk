/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macis <macis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:34:42 by macis             #+#    #+#             */
/*   Updated: 2022/07/01 22:35:08 by macis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_putchar(int c);
int		ft_putstr(char *c);
int		ft_putnbr(int a);
int		printf_write(char a, va_list macro);
int		ft_printf(const char *str, ...);
int		ft_convert(size_t i, char *taban);
size_t	ft_strlen(const char *s);

#endif
