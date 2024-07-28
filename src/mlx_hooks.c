/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:19:11 by nrauh             #+#    #+#             */
/*   Updated: 2024/07/28 14:41:09 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		cleanup_and_exit(game);
	if (!game->game_won)
		move_player(keysym, game);
	return (0);
}

int	exit_with_x(t_game *game)
{
	cleanup_and_exit(game);
	return (1);
}

int	render(t_game *game)
{
	if (!game_won(game))
		render_player(game);
	return (0);
}
