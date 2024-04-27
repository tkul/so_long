/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 02:27:29 by tkul              #+#    #+#             */
/*   Updated: 2024/04/28 02:27:31 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_redraw_map(t_state *state)
{
	int		x;
	int		y;

	y = 0;
	while (y < state->map->height)
	{
		x = 0;
		while (x < state->map->width)
		{
			if (state->map->board[y][x] == 'P')
				state->map->board[y][x] = '0';
			x++;
		}
		y++;
	}
	state->map->board[state->player->y][state->player->x] = 'P';
}

int	is_next_tile_is(t_state *state, int direction, char tile)
{
	if (direction == RIGHT_DIR)
	{
		if (state->map->board[state->player->y][state->player->x + 1] == tile)
			return (1);
	}
	else if (direction == LEFT_DIR)
	{
		if (state->map->board[state->player->y][state->player->x - 1] == tile)
			return (1);
	}
	else if (direction == DOWN_DIR)
	{
		if (state->map->board[state->player->y + 1][state->player->x] == tile)
			return (1);
	}
	else if (direction == UP_DIR)
	{
		if (state->map->board[state->player->y - 1][state->player->x] == tile)
			return (1);
	}
	return (0);
}

int	check_logic(t_state *state, int direction)
{
	if (is_next_tile_is(state, direction, '1'))
		return (0);
	if (is_next_tile_is(state, direction, 'C'))
		state->collectiables--;
	if (is_next_tile_is(state, direction, 'E') && state->collectiables == 0)
	{
		state->player->moves++;
		ft_printf("You win! Total Moves %d\n", state->player->moves);
		mlx_destroy_window(state->mlx, state->win);
		free_state(state);
		exit(0);
	}
	state->player->moves++;
	ft_printf("Moves: %d\n", state->player->moves);
	return (1);
}

void	player_move(t_state *state, int direction)
{
	if (!check_logic(state, direction))
		return ;
	if (state->player->x == state->exit->x
		&& state->player->y == state->exit->y)
		state->map->board[state->player->y][state->player->x] = 'E';
	else
		state->map->board[state->player->y][state->player->x] = '0';
	if (direction == RIGHT_DIR)
		state->player->x++;
	else if (direction == LEFT_DIR)
		state->player->x--;
	else if (direction == DOWN_DIR)
		state->player->y++;
	else if (direction == UP_DIR)
		state->player->y--;
	state->map->board[state->player->y][state->player->x] = 'P';
}
