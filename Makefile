# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 18:57:15 by anaji-el          #+#    #+#              #
#    Updated: 2022/03/15 18:57:56 by anaji-el         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

CC = cc
FLAGS = -Wall -Wextra -Werror

all:

	@$(CC) $(FLAGS) client.c  -o $(CLIENT)

	@$(CC) $(FLAGS) server.c  -o $(SERVER)
	
	@$(CC) $(FLAGS) client_bonus.c  -o $(CLIENT_BONUS)

	@$(CC) $(FLAGS) server_bonus.c  -o $(SERVER_BONUS)

	
%.o:%.c 
	@$(CC) $(FLAGS)

clean:
	@rm -f $(CLIENT) $(SERVER)
	@rm -f $(CLIENT_BONUS) $(SERVER_BONUS)

fclean: clean
	@rm -f $(CLIENT) $(SERVER)
	@rm -f $(CLIENT_BONUS) $(SERVER_BONUS)
	
re: fclean all