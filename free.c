/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:31:53 by tkul              #+#    #+#             */
/*   Updated: 2024/04/28 01:31:56 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->board[i]);
		i++;
	}
	free(map->board);
	free(map);
}

void	free_state(t_state *state)
{
	if (state->map)
		free_map(state->map);
	if (state->player)
		free(state->player);
	if (state->img_paths)
		free(state->img_paths);
	if (state->exit)
		free(state->exit);
	free(state);
}
