/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:55:27 by nrauh             #+#    #+#             */
/*   Updated: 2024/07/26 16:11:03 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_moves_background(t_game *game, int x, int y)
{
	t_position	pos;

	pos.x = TILE_SIZE * x;
	pos.y = TILE_SIZE * y;
	mlx_put_image_to_window(game->mlx, game->win, 
		game->back->img, pos.x, pos.y);
}

void	display_moves(t_game *game)
{
	char			*moves;
	char			*new_str;

	render_moves_background(game, 0, 0);
	render_moves_background(game, 1, 0);
	moves = ft_itoa(game->move_count);
	if (!moves)
		return ;
	new_str = ft_strjoin("MOVES ", moves);
	free(moves);
	if (!new_str)
		return ;
	free(game->display_moves);
	game->display_moves = new_str;
	mlx_string_put(game->mlx, game->win, 12, 20, 0x000000, \
		game->display_moves);
}

void	display_end(t_game *game)
{
	char			*new_str;

	if (game->game_won == 0)
	{
		render_moves_background(game, 0, 0);
		render_moves_background(game, 1, 0);
		new_str = ft_strdup("YOU WON");
		if (!new_str)
			return ;
		free(game->display_moves);
		game->display_moves = new_str;
		mlx_string_put(game->mlx, game->win, 12, 20, 0x000000, \
			game->display_moves);
	}
}
