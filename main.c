/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:32:38 by tkul              #+#    #+#             */
/*   Updated: 2024/04/28 03:21:06 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_state(t_state *state)
{
	state->map_path = NULL;
	state->map = NULL;
	state->player = NULL;
	state->img_paths = NULL;
	state->mlx = NULL;
	state->win = NULL;
	state->exit = NULL;
}

int	main(int ac, char **av)
{
	t_state	*state;

	if (ac != 2)
		exit_err(1, "You have to pass 2 arguments", NULL);
	state = malloc(sizeof(t_state));
	if (state == NULL)
		exit_err(1, "Failed to open malloc", NULL);
	init_state(state);
	state->map_path = av[1];
	ft_check_map(state);
	ft_window(state);
	return (0);
}
