# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 16:23:20 by nrauh             #+#    #+#              #
#    Updated: 2024/07/28 16:05:35 by nrauh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long

LIBFT_DIR = ./libft
LIBFT = libft.a
LIBFT_AR = $(addprefix $(LIBFT_DIR), $(LIBFT))

MLX_DIR = ./mlx_linux
MLX = libmlx.a
MLX_AR = $(addprefix $(MLX_DIR), $(MLX))

RM = rm -f
INCLUDES = -I includes

SRCS = main.c \
	$(addprefix src/, mlx_hooks.c free_mem.c load_img.c render_img.c \
	move_player.c parse_map.c game_logic.c init_game.c display_moves.c) \
	$(addprefix src/check_map/, check_map.c check_map_helper.c flood_fill.c) \
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT_AR):
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) .
	mv $(LIBFT) $(NAME)

$(MLX_AR):
	make -C $(MLX_DIR)
	cp $(MLX_DIR)/$(MLX) .
	mv $(MLX) $(NAME)

$(NAME): $(OBJS) $(LIBFT_AR) $(MLX_AR)
	$(CC) $(OBJS) $(LIBFT_DIR)/$(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -g -Imlx_linux -O3 -c $< -o $@

clean:
	make clean -C libft
	make clean -C mlx_linux
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX) $(NAME)

re: fclean all

.PHONY: all clean fclean re
