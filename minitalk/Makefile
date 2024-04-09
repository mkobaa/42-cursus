# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 10:26:22 by mkobaa            #+#    #+#              #
#    Updated: 2024/02/10 01:42:52 by mkobaa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf\s_utils.c	ft_printf\utils.c	ft_printf\ft_printf.c
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
