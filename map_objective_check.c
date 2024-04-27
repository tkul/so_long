/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_objective_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:33:16 by tkul              #+#    #+#             */
/*   Updated: 2024/04/28 01:33:19 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_objects_valid(t_objects *obj, t_state *state)
{
	if (obj->collectiables < 1)
	{
		free(obj);
		exit_err(1, "Collectiables is not enough!", state);
	}
	if (obj->exit != 1)
	{
		free(obj);
		exit_err(1, "Exit is not one!", state);
	}
	if (obj->player != 1)
	{
		free(obj);
		exit_err(1, "Player is not one!", state);
	}
}

void	map_objective_checker(t_state *state)
{
	t_objects	*obj;
	int			i;
	char		*row;

	obj = malloc(sizeof(t_objects));
	if (obj == NULL)
		exit_err(1, "Failed to open malloc", state);
	i = -1;
	obj->collectiables = 0;
	obj->exit = 0;
	obj->player = 0;
	while (++i < state->map->height)
	{
		if (!is_valid_row(state->map->board[i]))
			exit_err(1, "Map is not valid!", state);
		row = state->map->board[i];
		obj->collectiables = obj->collectiables + count_len_of(row, 'C');
		obj->exit = obj->exit + count_len_of(row, 'E');
		obj->player = obj->player + count_len_of(row, 'P');
	}
	is_objects_valid(obj, state);
	state->collectiables = obj->collectiables;
	free(obj);
}
