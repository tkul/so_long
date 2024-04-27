/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 00:53:31 by tkul              #+#    #+#             */
/*   Updated: 2023/12/02 00:53:31 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_control(char symbol, int i, va_list *argv)
{
	if (symbol == '%')
		i = ft_putchar('%', i);
	else if (symbol == 'c')
		i = ft_putchar(va_arg(*argv, int), i);
	else if (symbol == 's')
		i = ft_putstr(va_arg(*argv, char *), i);
	else if (symbol == 'd' || symbol == 'i')
		i = ft_putnbr((long)va_arg(*argv, int), i);
	else if (symbol == 'p')
		i = ft_putadress(va_arg(*argv, void *), i);
	else if (symbol == 'u')
		i = ft_putnbr_u(va_arg(*argv, unsigned int), i);
	else if (symbol == 'x' || symbol == 'X')
		i = ft_puthex(va_arg(*argv, unsigned int), i, symbol);
	else
		i = ft_putchar(symbol, i);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int				i;
	unsigned char	*s;
	va_list			argv;

	i = 0;
	s = (unsigned char *)format;
	va_start(argv, format);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			if (!(*s))
				continue ;
			i = ft_control(*s, i, &argv);
		}
		else
			i = ft_putchar(*s, i);
		s++;
	}
	va_end(argv);
	return (i);
}
