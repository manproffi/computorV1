# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 19:55:14 by sprotsen          #+#    #+#              #
#    Updated: 2018/10/08 19:55:15 by sprotsen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor

SRC = main.cpp validation.cpp calculation.cpp

OBJ = $(SRC:.cpp=.o)

CFLAGS = -std=c++11 -Wall -Wextra -Werror

CC = clang++

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c  -o $@ $< 

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
