/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:25:50 by nrauh             #+#    #+#             */
/*   Updated: 2024/07/28 14:01:17 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_wall(t_game *game, int next_y, int next_x)
{
	if (game->map[next_y][next_x] == '1')
		return (1);
	return (0);
}

void	get_collectable(t_game *game, int next_y, int next_x)
{
	if (game->map[next_y][next_x] == 'C')
	{
		game->map[next_y][next_x] = '0';
		game->collected++;
	}
}

int	check_next_position(t_game *game, int next_y, int next_x)
{
	if (is_wall(game, next_y, next_x))
		return (0);
	get_collectable(game, next_y, next_x);
	game->move_count++;
	display_moves(game);
	rerender_background(game);
	return (1);
}

int	move_player(int keysym, t_game *game)
{
	if (keysym == XK_w || keysym == XK_Up)
	{
		if ((game->player_y > 1)
			&& check_next_position(game, game->player_y - 1, game->player_x))
			game->player_y--;
	}
	else if (keysym == XK_a || keysym == XK_Left)
	{
		if ((game->player_x > 1) 
			&& check_next_position(game, game->player_y, game->player_x - 1))
			game->player_x--;
	}
	else if (keysym == XK_s || keysym == XK_Down)
	{
		if ((game->player_y < game->height - 2) 
			&& check_next_position(game, game->player_y + 1, game->player_x))
			game->player_y++;
	}
	else if (keysym == XK_d || keysym == XK_Right)
	{
		if ((game->player_x < game->width - 2) 
			&& check_next_position(game, game->player_y, game->player_x + 1))
			game->player_x++;
	}
	return (0);
}
