GCC = gcc
CFLAG = -Wall -Wextra -Werror
ARFLAGES = crs
NAME = libft.a
SRCS =  ft_memset.c ft_strlen.c ft_putchar_fd.c ft_strmapi.c \
		ft_atoi.c ft_lstdelone.c ft_putendl_fd.c ft_strncmp.c \
		ft_bzero.c  ft_putnbr_fd.c ft_strnstr.c ft_calloc.c \
		ft_putstr_fd.c ft_strrchr.c ft_isalnum.c ft_lstmap.c \
		ft_split.c ft_strtrim.c ft_isalpha.c  ft_strchr.c \
		ft_substr.c ft_isascii.c  ft_strdup.c ft_tolower.c \
		ft_isdigit.c ft_memchr.c ft_striteri.c ft_toupper.c \
		ft_isprint.c ft_memcmp.c ft_strjoin.c ft_itoa.c \
		ft_memcpy.c ft_strlcat.c ft_memmove.c ft_strlcpy.c
OBJS = $(SRCS:.c=.o)
BNS_SRCS = ft_lstadd_front.c ft_lstclear.c ft_lstiter.c ft_lstlast.c \
		ft_lstnew.c ft_lstsize.c ft_lstadd_back.c
BNS_OBJS = $(BNS_SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	$(GCC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGES) $@ $^

clean:
	$(RM) $(OBJS)
	$(RM) $(BNS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS) $(BNS_OBJS)
	$(AR) $(ARFLAGES) $(NAME) $^