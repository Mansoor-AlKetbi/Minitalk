NAME = minitalk.a

CLIENT = client.c

SERVER = server.c

CLIENT_NAME = client

SERVER_NAME = server

CLIENT_BONUS = client_bonus.c

SERVER_BONUS = server_bonus.c

CLIENT_NAME_BONUS = client_bonus

SERVER_NAME_BONUS = server_bonus

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

all:  $(CLIENT_NAME) $(SERVER_NAME)

$(SERVER_NAME) : $(SERVER)
	$(CC) $(FLAGS) $(SERVER) -o $(SERVER_NAME)

$(CLIENT_NAME) : $(CLIENT)
	$(CC) $(FLAGS) $(CLIENT) -o $(CLIENT_NAME)

$(SERVER_NAME_BONUS) : $(SERVER_BONUS)
	$(CC) $(FLAGS) $(SERVER_BONUS) -o $(SERVER_NAME_BONUS)

$(CLIENT_NAME_BONUS) : $(CLIENT_BONUS)
	$(CC) $(FLAGS) $(CLIENT_BONUS) -o $(CLIENT_NAME_BONUS)

bonus: $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

clean:
	$(RM) server.o client.o
	$(RM) server_bonus.o client_bonus.o

fclean: clean
	$(RM) server client
	$(RM) server_bonus client_bonus minitalk.a

re: fclean all bonus

.PHONY:	all clean fclean re
