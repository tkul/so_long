/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 00:53:42 by tkul              #+#    #+#             */
/*   Updated: 2023/12/02 00:53:42 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c, int i)
{
	write(1, &c, 1);
	return (++i);
}

int	ft_putstr(char *s, int i)
{
	int	x;

	x = 0;
	if (!s)
		return (ft_putstr("(null)", i));
	while (s[x])
	{
		i = ft_putchar(s[x], i);
		x++;
	}
	return (i);
}

int	ft_putnbr(long n, int i)
{
	if (n < 0)
	{
		i = ft_putchar('-', i);
		n *= -1;
	}
	if (n > 9)
	{
		i = ft_putnbr(n / 10, i);
		i = ft_putnbr(n % 10, i);
	}
	else
		i = ft_putchar(n + '0', i);
	return (i);
}

int	ft_putnbr_u(unsigned int n, int i)
{
	if (n > 9)
	{
		i = ft_putnbr_u(n / 10, i);
		i = ft_putnbr_u(n % 10, i);
	}
	else
		i = ft_putchar(n + '0', i);
	return (i);
}
