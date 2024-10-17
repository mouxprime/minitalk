# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mianni <mianni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 14:03:52 by mianni            #+#    #+#              #
#    Updated: 2024/08/10 16:12:07 by mianni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

all: server client

bonus: all

server: server.o $(LIBFT)
	$(CC) $(CFLAGS) server.o $(LIBFT) -o server

client: client.o $(LIBFT)
	$(CC) $(CFLAGS) client.o $(LIBFT) -o client

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT_DIR) clean
	
fclean: clean
	rm -f server client $(LIBFT)

re: fclean all

.PHONY: all bonus clean fclean re
