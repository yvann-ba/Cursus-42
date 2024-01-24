# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 11:15:20 by ybarbot           #+#    #+#              #
#    Updated: 2024/01/24 10:31:24 by ybarbot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror -g 

SRCS = src/parsing.c src/parsing_utils.c src/actions.c src/actions2.c \
src/main.c src/sort_num.c src/sort_utils.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I/usr/include -I$(LIBFT_DIR)/includes

.PHONY: all clean fclean re libft

all: $(NAME)

$(LIBFT):
	$(MAKE) bonus --quiet -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)
	$(MAKE) --quiet -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) --quiet -C $(LIBFT_DIR) fclean

re: fclean all