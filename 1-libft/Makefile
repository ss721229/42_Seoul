GCC = gcc
CFLAG = -Wall -Wextra -Werror
ARFLAGES = crs

NAME = libft.a
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
INCLUDES = libft.h

all: $(NAME)

%.o: %.c
	$(GCC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGES) $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: