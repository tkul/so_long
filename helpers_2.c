/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 05:11:56 by egumus            #+#    #+#             */
/*   Updated: 2024/04/26 23:32:15 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*ft_locate(t_state *state, char c)
{
	int	*loc;
	int	i;
	int	j;

	loc = malloc(sizeof(int) * 2);
	if (loc == NULL)
		exit_err(1, "Failed to open malloc", state);
	i = 0;
	while (i < state->map->height)
	{
		j = 0;
		while (j < state->map->width)
		{
			if (state->map->board[i][j] == c)
			{
				loc[0] = i;
				loc[1] = j;
				return (loc);
			}
			j++;
		}
		i++;
	}
	return (loc);
}

int	ft_close(t_state *state)
{
	mlx_destroy_window(state->mlx, state->win);
	free_state(state);
	exit(0);
	return (0);
}
