/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:31:01 by nrauh             #+#    #+#             */
/*   Updated: 2024/07/28 14:41:04 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_rectangular(t_game *game)
{
	int		i;

	i = 0;
	game->width = (int)ft_strlen(game->map[i]);
	while (game->map[i])
	{
		if (game->width != (int)ft_strlen(game->map[i]))
			return (ft_printf("Error\nInvalid map, not rectangular!\n"), 0);
		i++;
	}
	return (1);
}

int	is_closed(t_game *game)
{
	int	r;
	int	c;

	r = 0;
	while (r < game->height)
	{
		c = 0;
		while (c < game->width)
		{
			if ((r == 0 || r == game->height - 1) && game->map[r][c] != '1')
				return (ft_printf("Error\nNo closed walls (first/last)\n"), 0);
			else if ((r > 0 || r < game->height - 1)
				&& (game->map[r][0] != '1' 
				|| game->map[r][game->width - 1] != '1'))
				return (ft_printf("Error\nNo closed walls (left/right)\n"), 0);
			c++;
		}
		r++;
	}
	return (1);
}

int	valid_char_type(t_game *game)
{
	int	r;
	int	c;

	r = 0;
	while (r < game->height)
	{
		c = 0;
		while (game->map[r][c])
		{
			if (game->map[r][c] == 'E' || game->map[r][c] == 'P'
				|| game->map[r][c] == '1' || game->map[r][c] == '0' 
				|| game->map[r][c] == 'C')
				c++;
			else
				return (ft_printf("Error\nInvalid char found in map!\n"), 0);
		}
		r++;
	}
	return (1);
}

int	count_chars(char *line, char c)
{
	int	count;

	count = 0;
	while (*line)
	{
		if (*line == c)
			count++;
		line++;
	}
	if (count > 0)
		return (count);
	return (0);
}

int	valid_char_count(t_game *game)
{
	int	r;
	int	e;
	int	p;
	int	c;

	r = 0;
	e = 0;
	p = 0;
	c = 0;
	while (r < game->height)
	{
		c += count_chars(game->map[r], 'C');
		p += count_chars(game->map[r], 'P');
		e += count_chars(game->map[r], 'E');
		r++;
	}
	if (e == 1 && p == 1 && c > 0)
		return (1);
	ft_printf("Error\nInvalid amount of Player, Exit or Collectables\n");
	return (0);
}
