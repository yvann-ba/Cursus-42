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

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

SRCS = 
OBJS = $(SRCS:.c=.o)

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

INCLUDES = -I/usr/include -Imlx -Ilibft

LIBFT = libft/libft.a

.PHONY: all clean fclean re libft

all: $(NAME)

libft:
	$(MAKE) -C libft

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all
