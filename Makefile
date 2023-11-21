NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
LIB = ./includes/libftprintf/libftprintf.a

SRC_FILES = main.c allocate_stacks.c stack_operations.c stack_operations1.c stack_operations2.c sort5.c sort3.c k_sort.c get_sorted_index.c
BSRC_FILES = checker.c

OBJS = $(addprefix .obj/, $(SRC_FILES:.c=.o))
BOBJS = $(addprefix .obj/, $(BSRC_FILES:.c=.o) $(filter-out main.o, $(SRC_FILES:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(OBJS) $(LIB) -o $(NAME) $(CFLAGS)

bonus: $(BOBJS) $(LIB)
	cc $(BOBJS) $(LIB) -o checker $(CFLAGS)
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