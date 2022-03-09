# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 02:02:38 by anaji-el          #+#    #+#              #
#    Updated: 2022/03/06 21:27:24 by anaji-el         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = Minitalk.a
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# RM = rm -f
# SRC_C = client.c
# SRC_S = server.c

# OBJ_C = $(SRC_C:.c=.o)
# OBJ_S = $(SRC_S:.c=.o)

# %.o: %.c Minitalk.h
# 	$(CC) $(CFLAGS) -c $<
		
# $(NAME): $(OBJ)
# 	ar rc $(NAME) $(OBJ)
	
# all : $(NAME)

# clean :
# 	$(RM) $(OBJ)

# fclean : clean
# 	$(RM) $(NAME)

# re: fclean $(NAME)

# .PHONY: all clean fclean re

NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SERVER = server.c
CLIENT = client.c


SERVER_BONUS = server_bonus.c
CLIENT_BONUS = client_bonus.c

OBJ_S = $(SERVER:.c=.o)
OBJ_C = $(CLIENT:.c=.o)

OBJ = $(SRC:.c=.o)

OBJ_S_BONUS = $(SERVER_BONUS:.c=.o)
OBJ_C_BONUS = $(CLIENT_BONUS:.c=.o)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(OBJ_S) $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_S)  -o server
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_C)  -o client

all : $(NAME)

bonus : $(OBJ) $(OBJ_S_BONUS) $(OBJ_C_BONUS)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_S_BONUS)  -o server_bonus
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_C_BONUS)  -o client_bonus

clean :
	$(RM) $(OBJ) $(OBJ_S) $(OBJ_C) $(OBJ_S_BONUS) $(OBJ_C_BONUS) server client server_bonus client_bonus

fclean : clean
	$(RM) $(NAME)

re: fclean $(NAME)
