/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:44:01 by nrauh             #+#    #+#             */
/*   Updated: 2024/07/28 14:48:09 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_printf("Error\nInvalid nr of arguments\n");
	if (argc == 2 && map_file_type(argv[1]) == 0)
	{
		game = NULL;
		game = init_map(game);
		if (game && parse_map(argv[1], game) && map_is_valid(game))
			game_loop(game);
		cleanup_and_exit(game);
	}
	return (0);
}
