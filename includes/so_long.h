/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:26:56 by nrauh             #+#    #+#             */
/*   Updated: 2024/07/28 14:31:04 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

# define TILE_SIZE 32
# define BACK "./assets/back.xpm"
# define EXIT "./assets/exit.xpm"
# define WALL "./assets/wall.xpm"
# define COLL "./assets/coll.xpm"
# define PLAYER "./assets/player.xpm"
# define EXIT_OPEN "./assets/exit_open.xpm"

typedef struct s_img {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_position {
	int		x;
	int		y;
}			t_position;

typedef struct s_game {
	void		*mlx;
	void		*win;
	char		**map;
	int			height;
	int			width;
	int			collectables;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			collected;
	int			exited;
	int			move_count;
	char		*display_moves;
	int			game_won;
	t_img		*back;
	t_img		*player;
	t_img		*wall;
	t_img		*exit;
	t_img		*exit_open;
	t_img		*coll;
	t_img		*moves;
}				t_game;

t_game		*init_map(t_game *game);
int			init_window(t_game *game);
int			init_mlx(t_game *game);
int			init_images(t_game *game);
int			map_file_type(char *str);
void		game_loop(t_game *game);
int			parse_map(char *map_path, t_game *game);
int			map_is_valid(t_game *game);
int			is_rectangular(t_game *game);
int			is_closed(t_game *game);
int			valid_char_type(t_game *game);
int			valid_char_count(t_game *game);
int			has_valid_path(t_game *game);
int			render(t_game *game);
int			load_img(t_game *game, t_img **img, char type);
void		put_images_to_window(t_game *game);
void		render_area(t_game *game, t_img **img, char type);
void		render_player(t_game *game);
void		render_exit(t_game *game, t_img **img);
void		rerender_background(t_game *game);
void		display_moves(t_game *game);
void		display_end(t_game *game);
int			move_player(int keysym, t_game *game);
int			game_won(t_game *game);
int			handle_keypress(int keysym, t_game *game);
int			exit_with_x(t_game *game);
void		cleanup_and_exit(t_game *game);
void		free_map(t_game *game);

#endif
