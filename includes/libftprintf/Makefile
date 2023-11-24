NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIB = libft/libft.a
SRCS = ft_printf.c print_idu.c print_ptr.c print_s.c print_xX.c \
		get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS) $(LIB)
	cp $(LIB) $(NAME)
	ar rcs $(NAME) $(OBJS) $(LIB)
$(LIB):
	cd libft && make
clean:
	rm -f $(OBJS)
	cd libft && make fclean
fclean: clean
	rm -f $(NAME)
	cd libft && make fclean
re: fclean $(NAME)

.PHONY: clean fclean re all