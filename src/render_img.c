/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:43:13 by nrauh             #+#    #+#             */
/*   Updated: 2024/07/26 15:55:07 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_area(t_game *game, t_img **img, char type)
{
	int			c;
	int			l;
	t_position	pos;

	c = 0;
	l = 0;
	while (l < game->height)
	{
		while (c < game->width)
		{
			if (game->map[l][c] == type)
			{
				pos.x = TILE_SIZE * c;
				pos.y = TILE_SIZE * l;
				mlx_put_image_to_window(game->mlx, game->win, 
					(*img)->img, pos.x, pos.y);
			}
			c++;
		}
		c = 0;
		l++;
	}
}

void	render_player(t_game *game)
{
	t_position	pos;

	pos.x = TILE_SIZE * game->player_x;
	pos.y = TILE_SIZE * game->player_y;
	mlx_put_image_to_window(game->mlx, game->win, 
		game->player->img, pos.x, pos.y);
}

void	render_exit(t_game *game, t_img **img)
{
	t_position	pos;

	pos.x = game->exit_x * TILE_SIZE;
	pos.y = game->exit_y * TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->win,
		(*img)->img, pos.x, pos.y);
}

void	rerender_background(t_game *game)
{
	t_position	pos;

	pos.x = TILE_SIZE * game->player_x;
	pos.y = TILE_SIZE * game->player_y;
	mlx_put_image_to_window(game->mlx, game->win, 
		game->back->img, pos.x, pos.y);
}

void	put_images_to_window(t_game *game)
{
	render_area(game, &game->back, '0');
	render_area(game, &game->wall, '1');
	render_area(game, &game->coll, 'C');
	render_player(game);
	render_exit(game, &game->exit);
}
