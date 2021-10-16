# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 20:24:30 by tcynthia          #+#    #+#              #
#    Updated: 2021/10/04 20:25:23 by tcynthia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client

NAME2 = server

LIB1 = ./clients/client.h

LIB2 = ./servers/server.h

SRC1 = ./clients/client.c

SRC2 = ./servers/server.c

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

CC = gcc

CFLAGC = -Wall -Wextra -Werror -I.

RM = rm -f

all: $(NAME1) $(NAME2) 

$(NAME1): $(OBJ1)
	$(CC) $(FLAGS) $(OBJ1) -o $(NAME1)

$(NAME2): $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2)

%.o: %.c
	$(CC) $(CFLAGC) -c $< -o $@

clean:
	$(RM) $(OBJ1) $(OBJ2)

fclean: clean
	$(RM) $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
