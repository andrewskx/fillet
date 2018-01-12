# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user01 <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/07 21:11:04 by user01            #+#    #+#              #
#    Updated: 2017/12/08 20:23:40 by anboscan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SRC = *.c
OBJ = *.o
NAME = fillit

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) -o $(NAME)

$(OBJ):
		@$(CC) $(CFLAGS) $(SRC)
clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean all
