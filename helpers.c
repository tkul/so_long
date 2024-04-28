/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:32:19 by tkul              #+#    #+#             */
/*   Updated: 2024/04/28 03:22:44 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_full_of(char *str, int len, char c)
{
	int	i;

	i = 0;
	while (len)
	{
		if (str[len - 1] != c)
			return (0);
		len--;
	}
	return (1);
}

int	is_valid_row(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C' && str[i] != 'E'
			&& str[i] != 'P')
			return (0);
		i++;
	}
	return (1);
}

int	count_len_of(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

t_map	*ft_create_map(int w, int h, t_state *state)
{
	int		j;
	char	**board;
	char	*line;
	t_map	*map;

	board = malloc(sizeof(char *) * (h));
	if (board == NULL)
		exit_err(1, "Cant Malloc", state);
	j = 0;
	while (j < h)
	{
		line = malloc(sizeof(char) * (w));
		if (line == NULL)
			exit_err(1, "Cant Malloc", state);
		board[j] = line;
		j++;
	}
	map = malloc(sizeof(t_map));
	if (map == NULL)
		exit_err(1, "Cant Malloc", state);
	map->board = board;
	map->height = h;
	map->width = w;
	return (map);
}

t_map	*copy_map(t_map *map, t_state *state)
{
	t_map	*m;
	char	*line;
	int		i;

	m = ft_create_map(map->width, map->height, state);
	i = 0;
	while (i < map->height)
	{
		line = map->board[i];
		ft_strlcpy(m->board[i], line, map->width + 1);
		i++;
	}
	return (m);
}
