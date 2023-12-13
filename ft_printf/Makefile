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
