/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:11:38 by nrauh             #+#    #+#             */
/*   Updated: 2024/07/28 14:42:21 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_path(char type)
{
	if (type == 'E')
		return (EXIT);
	else if (type == '1')
		return (WALL);
	else if (type == '0')
		return (BACK);
	else if (type == 'C')
		return (COLL);
	else if (type == 'P')
		return (PLAYER);
	else if (type == 'F')
		return (EXIT_OPEN);
	else
		return (NULL);
}

int	load_img(t_game *game, t_img **img, char type)
{
	int		img_width;
	int		img_height;

	*img = malloc(sizeof(t_img));
	if (!img) 
		return (ft_printf("Error\nAllocation for image image failed\n"), 0);
	img_width = TILE_SIZE;
	img_height = TILE_SIZE;
	(*img)->img = mlx_xpm_file_to_image(game->mlx, get_path(type), 
			&img_width, &img_height);
	if ((*img)->img == NULL)
	{
		free(*img);
		*img = NULL;
		return (ft_printf("Error\nFile to img failed!\n"), 0);
	}
	return (1);
}
