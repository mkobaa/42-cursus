# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 10:26:22 by mkobaa            #+#    #+#              #
#    Updated: 2023/12/19 10:26:24 by mkobaa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = other_funcs.c	some_funcs.c	ft_printf.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c ft_printf.h
		$(CC) $(FLAGS) -c $<

$(NAME) : $(OBJ)
		ar -rcs $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
