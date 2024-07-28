/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:08:00 by nrauh             #+#    #+#             */
/*   Updated: 2024/07/26 16:40:02 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (i < game->height)
		{
			free(game->map[i]);
			game->map[i] = NULL;
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
	game->width = 0;
	game->height = 0;
}

void	free_and_destroy_image(t_game *game, t_img **img_pointer)
{
	mlx_destroy_image(game->mlx, (*img_pointer)->img);
	free(*img_pointer);
}

void	cleanup_and_exit(t_game *game)
{
	if (game->back)
		free_and_destroy_image(game, &game->back);
	if (game->wall)
		free_and_destroy_image(game, &game->wall);
	if (game->coll)
		free_and_destroy_image(game, &game->coll);
	if (game->exit)
		free_and_destroy_image(game, &game->exit);
	if (game->exit_open)
		free_and_destroy_image(game, &game->exit_open);
	if (game->player)
		free_and_destroy_image(game, &game->player);
	if (game->display_moves)
		free(game->display_moves);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game);
	free(game);
	exit (0);
}
