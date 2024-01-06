# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 12:39:25 by ybarbot           #+#    #+#              #
#    Updated: 2024/01/06 09:43:29 by ybarbot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = src/get_map.c src/map_utils.c  src/check_valid_map.c \
src/init.c src/research_exit.c src/research_collectible.c \
OBJS = $(SRCS:.c=.o)

NAME = so_long
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
