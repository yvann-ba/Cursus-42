# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 12:39:25 by ybarbot           #+#    #+#              #
#    Updated: 2024/01/07 10:58:48 by ybarbot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror -g 

SRCS = src/get_map.c src/map_utils.c  src/check_valid_map.c \
src/init.c src/research_backtrack.c
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
	$(MAKE) --quiet -C $(LIBFT_DIR)

mlx:
	$(MAKE) --quiet -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) $(LIBFT)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)
	$(MAKE) --quiet -C $(LIBFT_DIR) clean
	$(MAKE) --quiet -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) --quiet -C $(LIBFT_DIR) fclean
	# $(MAKE) --quiet -C $(MLX_DIR) fclean

re: fclean all
