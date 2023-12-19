# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yvann <yvann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 12:39:25 by ybarbot           #+#    #+#              #
#    Updated: 2023/12/14 11:32:49 by yvann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

NAME = so_long

SRCS = parsing/map_utils.c parsing/get_map.c parsing/check_valid_map.c
OBJS = $(SRCS:.c=.o)

MLX_FLAGS = -Llibs/mlx -lmlx -L/usr/lib/X11 -lXext -lX11

LIBFT_DIR = libs/Libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I/usr/include -Imlx -I$(LIBFT_DIR)/includes

.PHONY: all clean fclean re libft

all: $(NAME)

libft:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
