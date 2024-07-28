/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:42:13 by nrauh             #+#    #+#             */
/*   Updated: 2024/07/28 14:38:25 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	game_won(t_game *game)
{
	if (game->collected == game->collectables)
	{
		render_exit(game, &game->exit_open);
		if (game->map[game->player_y][game->player_x] == 'E')
		{
			display_end(game);
			game->game_won = 1;
			return (1);
		}
	}
	else if (game->map[game->player_y][game->player_x] != 'E')
	{
		render_exit(game, &game->exit);
		return (0);
	}
	return (0);
}

void	game_loop(t_game *game)
{
	if (!init_mlx(game) || !init_images(game) || !init_window(game))
		cleanup_and_exit(game);
	put_images_to_window(game);
	mlx_loop_hook(game->mlx, &render, game);
	mlx_key_hook(game->win, &handle_keypress, game);
	mlx_hook(game->win, 33, 1L << 17, &exit_with_x, game);
	mlx_loop(game->mlx);
}
