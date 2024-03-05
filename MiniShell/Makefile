# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 11:12:16 by ybarbot           #+#    #+#              #
#    Updated: 2024/03/05 12:08:16 by ybarbot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/main.c src/parsing/tokenization.c src/parsing/tokenization_utils.c

OBJS = $(SRCS:.c=.o)

NAME = minishell

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