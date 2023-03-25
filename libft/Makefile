GCC = gcc
CFLAG = -Wall -Wextra -Werror
ARFLAGES = crs

NAME = libft.a
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(GCC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGES) $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: