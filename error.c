/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:31:34 by tkul              #+#    #+#             */
/*   Updated: 2024/04/28 01:50:45 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_err(int err_code, char *err_mess, t_state *state)
{
	if (state)
		free_state(state);
	ft_printf("[ERROR] Exited with %d error code: %s\n", err_code, err_mess);
	exit(1);
}
