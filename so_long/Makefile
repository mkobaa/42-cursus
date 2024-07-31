# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 01:29:00 by mkobaa            #+#    #+#              #
#    Updated: 2024/07/31 05:59:46 by mkobaa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = 
SRC = main.c	functions/function_1.c	get_next_line/get_next_line.c	get_next_line/get_next_line_utils.c \
		functions/ft_split.c functions/function_2.c	functions/function_3.c functions/ft_itoa.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c so_long.h
	$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
