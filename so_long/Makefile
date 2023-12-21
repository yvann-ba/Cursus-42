# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yvann <yvann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 12:39:25 by ybarbot           #+#    #+#              #
#    Updated: 2023/12/21 14:23:34 by yvann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = so_long

SRCS = parsing/map_utils.c parsing/get_map.c parsing/check_valid_map.c parsing/test_get_map.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = libs/mlx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11

LIBFT_DIR = libs/Libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I/usr/include -I$(MLX_DIR) -I$(LIBFT_DIR)/includes

.PHONY: all clean fclean re libft mlx

all: libft mlx $(NAME)

libft:
	$(MAKE) -C $(LIBFT_DIR)

mlx:
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) $(LIBFT)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	# $(MAKE) -C $(MLX_DIR) fclean

re: fclean all
