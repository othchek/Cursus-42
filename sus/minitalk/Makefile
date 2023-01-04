# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 12:09:19 by otchekai          #+#    #+#              #
#    Updated: 2023/01/04 11:14:15 by otchekai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

SRC_C = client.c
SRC_S = server.c
OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT) $(OBJ_C)
	@$(CC) $(CFLAGS) $(SRC_C) $(LIBFT) -o $(CLIENT)
	@printf "client ready.\n"

$(SERVER): $(LIBFT) $(OBJ_S)
	@$(CC) $(CFLAGS) $(SRC_S) $(LIBFT) -o $(SERVER)
	@printf "server ready.\n"

$(LIBFT):
	@ $(MAKE) -C ./libft

clean:
	@$(RM) $(CLIENT) $(SERVER)
	@$(RM) $(OBJ_C) $(OBJ_S)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean re fclean 