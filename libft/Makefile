NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = $(wildcard ./*.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all