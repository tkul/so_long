/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:32:27 by tkul              #+#    #+#             */
/*   Updated: 2024/04/28 02:23:23 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_state *state)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(state->mlx, state->win);
		free_state(state);
		exit(0);
	}
	else if (keycode == KEY_D)
		player_move(state, RIGHT_DIR);
	else if (keycode == KEY_S)
		player_move(state, DOWN_DIR);
	else if (keycode == KEY_A)
		player_move(state, LEFT_DIR);
	else if (keycode == KEY_W)
		player_move(state, UP_DIR);
	ft_put_images(state);
	return (0);
}
