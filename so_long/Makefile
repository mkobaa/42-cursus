# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 01:29:00 by mkobaa            #+#    #+#              #
#    Updated: 2024/08/01 05:23:42 by mkobaa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
      functions/ft_split.c functions/events.c functions/file_checks.c \
      functions/helpers.c functions/map_check.c functions/map_copies.c \
      functions/map_data.c functions/map_data_2.c functions/mlx_manag.c \
      functions/pac_moves.c functions/put_textures.c functions/errors.c functions/errors_2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c so_long.h
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

