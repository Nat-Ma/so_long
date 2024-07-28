/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:46:33 by nrauh             #+#    #+#             */
/*   Updated: 2024/07/28 14:42:08 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

t_game	*init_map(t_game *game)
{
	game = malloc(sizeof(t_game));
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->height = 0;
	game->width = 0;
	game->collectables = 0;
	game->back = NULL;
	game->player = NULL;
	game->wall = NULL;
	game->exit = NULL;
	game->exit_open = NULL;
	game->coll = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->collected = 0;
	game->exited = 0;
	game->move_count = 0;
	game->moves = NULL;
	game->display_moves = ft_strdup("");
	game->game_won = 0;
	return (game);
}

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (ft_printf("Error\nmlx initialization failed\n"), 0);
	return (1);
}

int	init_window(t_game *game)
{
	int		width;
	int		height;

	width = game->width * TILE_SIZE;
	height = game->height * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, width, height, "Egghunt");
	if (game->win == NULL)
	{
		free(game->win);
		return (ft_printf("Error\nWindow allocation failed\n"), 0);
	}
	return (1);
}

int	init_images(t_game *game)
{
	if (!load_img(game, &game->back, '0')
		|| !load_img(game, &game->wall, '1')
		|| !load_img(game, &game->coll, 'C')
		|| !load_img(game, &game->player, 'P')
		|| !load_img(game, &game->exit, 'E')
		|| !load_img(game, &game->exit_open, 'F'))
		return (0);
	return (1);
}
