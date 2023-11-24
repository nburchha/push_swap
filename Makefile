NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g
LIB = ./includes/libftprintf/libftprintf.a

SRC_FILES = main.c allocate_stacks.c stack_operations.c stack_operations1.c \
			stack_operations2.c sort5.c sort3.c k_sort.c get_sorted_index.c \
			allocate_utils.c free_exit.c
BSRC_FILES = checker.c
OBJS = $(addprefix .obj/, $(SRC_FILES:.c=.o))
BOBJS = $(addprefix .obj/, $(BSRC_FILES:.c=.o)) $(addprefix .obj/, $(filter-out main.o, $(SRC_FILES:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(OBJS) $(LIB) -o $(NAME) $(CFLAGS)

bonus: $(BONUS_NAME)
$(BONUS_NAME): $(BOBJS) $(LIB)
	cc $(BOBJS) $(LIB) -o $(BONUS_NAME) $(CFLAGS)
.obj/%.o: src/%.c
	mkdir -p .obj
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	cd includes/libftprintf && make all
clean:
	rm -f $(OBJS) $(BOBJS)
	cd includes/libftprintf && make fclean
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	cd includes/libftprintf && make fclean
re: fclean $(NAME)

.PHONY: clean fclean re all bonus