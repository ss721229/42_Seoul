CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = crs
NAME = libftprintf.a
SRCS = ft_printf_main.c ft_printf_conv_char.c \
		ft_printf_conv_hex.c ft_printf_conv_int.c \
		ft_printf_utils.c
OBJS = $(SRCS:.c=.o)
HEADER = ft_printf.h

all : $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all