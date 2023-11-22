NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
LIB = ./includes/libftprintf/libftprintf.a

SRC_FILES = main.c allocate_stacks.c stack_operations.c stack_operations1.c stack_operations2.c sort5.c sort3.c k_sort.c get_sorted_index.c #allocate_stack_util.c
BSRC_FILES = checker.c
BONUS_NAME = bonus_checker
OBJS = $(SRC_FILES:.c=.o) # addprefix .obj/, 
BOBJS = $(BSRC_FILES:.c=.o) $(filter-out main.o, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(OBJS) $(LIB) -o $(NAME) $(CFLAGS)

bonus: $(BONUS_NAME)
$(BONUS_NAME): $(BOBJS) $(LIB)
	cc $(BOBJS) $(LIB) -o $(BONUS_NAME) $(CFLAGS)
%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@
#	mkdir -p .obj

$(LIB):
	cd includes/libftprintf && make all
clean:
	rm -f */*.o *.o
	cd includes/libftprintf && make clean
fclean: clean
	rm -f $(NAME)
	cd includes/libftprintf && make fclean
re: fclean $(NAME)

.PHONY: clean fclean re all