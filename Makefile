NAME			=	push_swap
BONUS_NAME		=	checker

CC				=	clang
AR				=	ar -rcs
RM				=	rm -rfd
CFLAGS			=	-g -Wall -Wextra -Werror


LIBS_DIR		=	libs
INCLUDES_DIR	=	includes
SRC_DIR			=	src
OBJ_DIR			=	obj
PS_DIR			=	push_swap


PS_SRC_NAMES	=	is_space.c \
					strict_atoi.c \
					new_stack.c \
					destroy_stack.c \
					destroy_state.c \
					push_to_stack.c \
					pop_from_stack.c \
					swap_int.c \
					swap_stack_top.c \
					shift_stack.c \
					reverse_shift_stack.c \
					stack_shifter.c \
					sort_two_sized_stack.c \
					print_stack.c \
					print_state.c \
					new_state_from_input.c \
					replace_nl.c \
					sx.c \
					px.c \
					rx.c \
					rrx.c \
					create_op_item.c \
					add_to_op_list.c \
					remove_item_from_op_list.c \
					destroy_op_list.c \
					op_list_size.c \
					get_first_op_item.c \
					get_last_op_item.c 

BONUS_SRC		=	checker.c

P_S_RAW			=	push_swap.c

PS_OBJ_FILES	=	$(addprefix $(OBJ_DIR)/, $(PS_SRC_NAMES:.c=.o))
PS_SRC_FILES	=	$(addprefix $(SRC_DIR)/, $(addprefix	$(PS_DIR)/, $(PS_SRC_NAMES))) 
P_S_FILES		=	$(addprefix $(PS_DIR)/, $(P_S_RAW))


.PHONY: clean fclean re libft makechecker printtest re

printtest:
	@echo a

all: libft $(NAME)
	
bonus: all $(BONUS_NAME)

$(LIBS_DIR)/libpush_swap.a: $(PS_OBJ_FILES) 
	$(AR) $@ $(PS_OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(PS_DIR)/%.c
	@mkdir -p $(INCLUDES_DIR) $(OBJ_DIR)
	@cp -u $(SRC_DIR)/$(PS_DIR)/push_swap.h $(INCLUDES_DIR)/push_swap.h
	$(CC) $(CFLAGS) -c $< -I$(INCLUDES_DIR) -o $@

$(NAME): $(LIBS_DIR)/libpush_swap.a $(P_S_RAW)
	$(CC) $(CFLAGS) $(P_S_RAW) -L./$(LIBS_DIR) -lpush_swap -lft -I$(INCLUDES_DIR) -o $(NAME)

$(BONUS_NAME): $(LIBS_DIR)/libpush_swap.a $(BONUS_SRC)
	$(CC) $(CFLAGS) $(BONUS_SRC) -L./$(LIBS_DIR) -lpush_swap -lft -I$(INCLUDES_DIR) -o $(BONUS_NAME)

libft: 
	@mkdir -p $(LIBS_DIR) $(INCLUDES_DIR)
	make -C ./src/libft
	cp ./src/libft/libft.h $(INCLUDES_DIR)/libft.h
	cp ./src/libft/libft.a $(LIBS_DIR)/libft.a

clean:
	make clean -C ./src/libft

fclean: clean
	make fclean -C ./src/libft
	$(RM) $(INCLUDES_DIR) $(LIBS_DIR) $(OBJ_DIR)

re: fclean all
