# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 13:51:01 by ybarbot           #+#    #+#              #
#    Updated: 2024/02/13 18:54:55 by ybarbot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER_SRC = src/server.c
CLIENT_SRC = src/client.c

BONUS_SERVER_SRC = src_bonus/server_bonus.c
BONUS_CLIENT_SRC = src_bonus/client_bonus.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

BONUS_SERVER_OBJ = $(BONUS_SERVER_SRC:.c=.o)
BONUS_CLIENT_OBJ = $(BONUS_CLIENT_SRC:.c=.o)

SERVER_NAME = server
CLIENT_NAME = client

SERVER_BONUS_NAME = server_bonus
CLIENT_BONUS_NAME = client_bonus

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I/usr/include -I$(LIBFT_DIR)/includes

all: libft server client

bonus: libft server_bonus client_bonus

libft: $(LIBFT)

$(LIBFT):
	$(MAKE) bonus --quiet -C $(LIBFT_DIR)

server: $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER_NAME) $(LIBFT)

client: $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT_NAME) $(LIBFT)

server_bonus: $(BONUS_SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_SERVER_OBJ) -o $(SERVER_BONUS_NAME) $(LIBFT)

client_bonus: $(BONUS_CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_CLIENT_OBJ) -o $(CLIENT_BONUS_NAME) $(LIBFT)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(BONUS_SERVER_OBJ) $(BONUS_CLIENT_OBJ)
	$(MAKE) --quiet -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)
	$(MAKE) --quiet -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
