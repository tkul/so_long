/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 00:53:50 by tkul              #+#    #+#             */
/*   Updated: 2023/12/02 00:53:50 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar((num - 10 + 'A'), 1);
		}
	}
}

int	ft_puthex(unsigned int x, int i, char format)
{
	if (x == 0)
		return (ft_putchar('0', i));
	else
		ft_put_hex(x, format);
	return (i + ft_hex_len(x));
}
