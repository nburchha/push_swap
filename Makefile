NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIB = ./includes/libftprintf/libftprintf.a

SRCS = $(addprefix src/, $(SRC_FILES))
SRC_FILES = main.c allocate_stacks.c stack_operations.c test.c

OBJS = $(addprefix .obj/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	cc $(OBJS) $(LIB) -o $(NAME)

.obj/%.o: src/%.c
	mkdir -p .obj
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	cd includes/libftprintf && make all
clean:
	rm -f */*.o
	cd includes/libftprintf && make clean
fclean: clean
	rm -f $(NAME)
	cd includes/libftprintf && make fclean
re: fclean $(NAME)

.PHONY: clean fclean re all