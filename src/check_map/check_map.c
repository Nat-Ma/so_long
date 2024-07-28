/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:01:02 by nrauh             #+#    #+#             */
/*   Updated: 2024/07/28 14:41:18 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_game_coordinates(t_game *game)
{
	int	r;
	int	c;

	r = 0;
	while (r < game->height)
	{
		c = 0;
		while (game->map[r][c])
		{
			if (game->map[r][c] == 'C')
				game->collectables++;
			else if (game->map[r][c] == 'P')
			{
				game->player_x = c;
				game->player_y = r;
			}
			else if (game->map[r][c] == 'E')
			{
				game->exit_x = c;
				game->exit_y = r;
			}
			c++;
		}
		r++;
	}
}

int	map_file_type(char *str)
{
	size_t	len;
	int		valid;

	len = ft_strlen(str);
	valid = ft_strncmp(str + (len - 4), ".ber", 4);
	if (valid)
		ft_printf("Error\nFile type is invalid, should be .ber\n");
	return (valid);
}

int	map_is_valid(t_game *game)
{
	if (is_rectangular(game)
		&& is_closed(game)
		&& valid_char_type(game)
		&& valid_char_count(game))
	{
		set_game_coordinates(game);
		if (has_valid_path(game))
			return (1);
	}
	return (0);
}
