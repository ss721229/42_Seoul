CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = pipex
SRCS = pipex.c util.c util2.c util3.c
OBJS = pipex.o util.o util2.o util3.o
RM = rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re