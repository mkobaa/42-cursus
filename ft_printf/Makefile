# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 14:52:14 by mkobaa            #+#    #+#              #
#    Updated: 2023/12/07 20:47:46 by mkobaa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = ft_putnbr.c	ft_printhex.c	ft_putstr.c \
	ft_printf.c	ft_putchar.c	ft_putunsigned.c
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

re: fclean all%