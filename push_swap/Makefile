# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 15:34:19 by mkobaa            #+#    #+#              #
#    Updated: 2024/05/27 16:38:57 by mkobaa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf/s_utils.c	ft_printf/utils.c	ft_printf/ft_printf.c	push_swap.c parsing/parsing.c \
	utils/ft_split.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
