NAME_SERVER = server
NAME_CLIENT = client
CC = cc
FLAGS = -Wall -Wextra -Werror

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(SERVER_OBJ)
	$(CC) $(FLAGS) $(SERVER_OBJ) -o $(NAME_SERVER)

$(NAME_CLIENT): $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(CLIENT_OBJ) -o $(NAME_CLIENT)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all
