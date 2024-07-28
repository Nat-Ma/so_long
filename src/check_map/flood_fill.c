/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:33:43 by nrauh             #+#    #+#             */
/*   Updated: 2024/07/28 14:40:13 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**copy_map(t_game *game)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = calloc(sizeof(char *), (game->height + 1));
	if (!map_copy)
		return (ft_printf("Error\nAllocation of map copy failed!\n"), NULL);
	while (i < game->height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
		{
			while (i > 0)
			{
				free(map_copy[i - 1]);
				i--;
			}
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	return (map_copy);
}

void	flood_fill(t_game *game, char **map_copy, int x, int y)
{
	if (x < 1 || x > game->width || y < 1 || y > game->height
		|| map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	if (map_copy[y][x] == 'C')
		game->collected++;
	else if (map_copy[y][x] == 'E')
		game->exited++;
	map_copy[y][x] = 'V';
	flood_fill(game, map_copy, x + 1, y);
	flood_fill(game, map_copy, x - 1, y);
	flood_fill(game, map_copy, x, y - 1);
	flood_fill(game, map_copy, x, y + 1);
}

int	has_valid_path(t_game *game)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	flood_fill(game, map_copy, game->player_x, game->player_y);
	while (i < game->height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
	if (game->collectables == game->collected && game->exited == 1)
	{
		game->collected = 0;
		return (1);
	}
	return (ft_printf("Error\nInvalid path, exit or coll not reachable\n"), 0);
}
