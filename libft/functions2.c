/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 00:53:46 by tkul              #+#    #+#             */
/*   Updated: 2023/12/02 00:53:46 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_to_hex(size_t n, int i, char *set)
{
	if (n >= 16)
	{
		i = ft_to_hex(n / 16, i, set);
		i = ft_to_hex(n % 16, i, set);
	}
	else
		i = ft_putchar(set[n], i);
	return (i);
}

int	ft_putadress(void *p, int i)
{
	size_t	ptr;

	if (p == NULL)
	{
		i = ft_putstr("0x0", i);
	}
	else
	{
		ptr = (size_t)p;
		i = ft_putstr("0x", i);
		i = ft_to_hex(ptr, i, "0123456789abcdef");
	}
	return (i);
}
