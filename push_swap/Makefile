# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkobaa <mkobaa@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 11:38:07 by mkobaa            #+#    #+#              #
#    Updated: 2024/07/10 11:38:07 by mkobaa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra
SRC = main.c functions/ft_split.c functions/functions_1.c functions/functions_2.c functions/functions_3.c functions/functions_4.c \
		moves/moves_1.c moves/moves_2.c moves/moves_3.c algo/sort_cases.c functions/functions_5.c functions/functions_6.c algo/sort_more.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS)  -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
