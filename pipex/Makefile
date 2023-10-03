CC = cc
CFLAGS = -Wall -Werror -Wextra
ARFLAGS = crs
NAME = pipex.a
SRCS = pipex.c util.c util2.c util3.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re