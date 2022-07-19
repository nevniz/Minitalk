# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llawrenc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 18:30:10 by llawrenc          #+#    #+#              #
#    Updated: 2022/01/03 14:38:46 by llawrenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRC_SERVER = server.c support_functions.c
SRC_CLIENT = client.c support_functions.c

HEADER = minitalk.h

LIB = libft.a
LIB_SRC = -L./Libft -lft

OBJ_SERVER = $(SRC_SERVER:%.c=%.o)
OBJ_CLIENT = $(SRC_CLIENT:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re bonus

all : $(LIB) $(SERVER) $(CLIENT)

bonus : all

$(LIB) :
	make -C ./Libft all

$(SERVER) : $(OBJ_SERVER) $(HEADER)
	$(CC) $(OBJ_SERVER) $(LIB_SRC) -o $@

$(CLIENT) : $(OBJ_CLIENT) $(HEADER)
	$(CC) $(OBJ_CLIENT) $(LIB_SRC) -o $@

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make -C ./Libft clean
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean : clean
	make -C ./Libft fclean
	rm -f $(SERVER)
	rm -f $(CLIENT)

re : fclean all
