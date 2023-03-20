# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 12:09:19 by otchekai          #+#    #+#              #
#    Updated: 2023/03/20 10:42:42 by otchekai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MAKEFLAGS += -s
CLIENT = client
SERVER = server
CLIENTBONUS = clientbonus
SERVERBONUS = serverbonus

SRC_C = client.c
SRC_S = server.c
SRCB_C = client_bonus.c
SRCB_S = server_bonus.c
OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)
OBJB_C = $(SRCB_C:.c=.o)
OBJB_S = $(SRCB_S:.c=.o)
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT) $(OBJ_C)
	@$(CC) $(CFLAGS) $(SRC_C) $(LIBFT) -o $(CLIENT)
	@printf "client is ready.\n"

$(SERVER): $(LIBFT) $(OBJ_S)
	@ $(CC) $(CFLAGS) $(SRC_S) $(LIBFT) -o $(SERVER)
	@printf "server is on.\n"

$(LIBFT):
	@ $(MAKE) -C ./libft

bonus: $(CLIENTBONUS) $(SERVERBONUS)

$(CLIENTBONUS):	$(LIBFT) $(OBJB_C)
	@$(CC) $(CFLAGS) $(SRCB_C) $(LIBFT) -o $(CLIENTBONUS)
	@printf "clientbonus ready.\n"

$(SERVERBONUS):	$(LIBFT) $(OBJB_S)
	@$(CC) $(CFLAGS) $(SRCB_S) $(LIBFT) -o $(SERVERBONUS)
	@printf "serverbonus is on.\n"

clean:
	@$(RM) $(CLIENT) $(SERVER) $(CLIENTBONUS) $(SERVERBONUS)
	@$(RM) $(OBJ_C) $(OBJ_S) $(OBJB_C) $(OBJB_S)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean re fclean 