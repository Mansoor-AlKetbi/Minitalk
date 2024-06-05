
NAME = minitalk

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM		= rm -f

SRCS =	server.c
SRCC =	client.c

OBJS = $(SRCS:c=o)
OBJC = $(SRCC:c=o)

$(NAME): $(OBJS) $(OBJC)
		$(CC) $(CFLAGS) $(SRCS) -o server
		$(CC) $(CFLAGS) $(SRCC) -o client
%.o : %.c
	${CC} ${CFLAGS} -c $^

all:	$(NAME)

clean:
		@$(RM) $(OBJS) $(OBJC)

fclean:	clean
		$(RM) server client

re:		fclean all
