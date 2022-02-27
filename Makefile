# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 02:02:38 by anaji-el          #+#    #+#              #
#    Updated: 2022/02/27 02:03:17 by anaji-el         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minitalk.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = .....

OBJ = $(SRC:.c=.o)

%.o: %.c Minitalk.h
	$(CC) $(CFLAGS) -c $<
		
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	
all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re