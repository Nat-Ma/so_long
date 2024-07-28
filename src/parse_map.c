/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:20:14 by nrauh             #+#    #+#             */
/*   Updated: 2024/07/28 14:43:04 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	parse_map_helper(char *map_path, t_game *game, 
				int (*f)(int fd, t_game *game))
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nCould not open map\n"), 0);
	if (!f(fd, game))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	alloc_height(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (ft_printf("Error\nReading line from map failed!!\n"), 0);
	game->height = 1;
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->height += 1;
		free(line);
	}
	game->map = calloc((game->height + 1), sizeof(char *));
	if (!game->map)
		return (ft_printf("Error\nAllocation of map height failed\n"), 0);
	return (1);
}

int	alloc_width(int fd, t_game *game)
{
	int		i;
	char	*line;
	char	*trimmed;

	i = 0;
	while (i < game->height)
	{
		line = get_next_line(fd);
		if (!line)
			return (ft_printf("Error\nReading line from map failed\n"), 0);
		trimmed = ft_strtrim(line, "\n");
		if (!trimmed)
			return (ft_printf("Error\nTrimming newline from line failed\n"), 0);
		free(line);
		game->width = ft_strlen(trimmed);
		game->map[i] = trimmed;
		trimmed = NULL;
		i++;
	}
	game->map[i] = NULL;
	return (1);
}

int	parse_map(char *map_path, t_game *game)
{
	if (!parse_map_helper(map_path, game, alloc_height))
		return (0);
	if (!parse_map_helper(map_path, game, alloc_width))
		return (0);
	return (1);
}
