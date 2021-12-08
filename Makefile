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

GNL_SRC			=	get_next_line.c \
					get_next_line_utils.c
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
					build_base_merge_list.c \
					get_last_op_item.c \
					print_operations.c \
					get_index_of.c \
					build_keep_stack.c \
					get_stack_top.c \
					optmize_op_list.c \
					stack_is_sorted.c \
					sort_three_sized_stack.c \
					merge_into_b.c \
					merge_into_a.c \
					count_tuple_elements.c \
					mutate_merge_sequence.c \
					do_a_merge.c \
					merge_sort.c \
					new_operator.c \
					destroy_operator.c \
					add_operator.c \
					swap_int_array_values.c \
					find_resonable_sequence_in_a.c \
					copy_stack_a_to_b.c \
					heap_sort_by_greater.c \
					position_zero_at_top.c \
					build_array_of_indexes.c \
					calc_rotations.c \
					get_target.c \
					calc_insert_cost.c \
					clean_cost_struct.c \
					path_without_combination.c \
					max_in_stack.c \
					min_in_stack.c \
					heap_sort_array.c \
					replace_stack_values.c \
					get_min.c \
					eval_ra_rb.c \
					eval_ra_rrb.c \
					eval_rrb_rra.c \
					eval_rb_rra.c \
					copy_cost.c \
					push_filtered_region_to_b.c \
					push_allowed_sectors_to_b.c \
					quick_selection.c \
					get_best_cost_i.c \
					start_cost_array.c \
					destroy_cost_array.c \
					clean_cost_array.c \
					build_cost_array.c \
					get_next_cost.c \
					get_prev_cost.c \
					radix_sort.c \
					sort_four_sized.c \
					sort_five_sized.c \
					rotate_as_needed.c \
					execute_best_cost.c \
					combine_vertical_moves.c \
					destroy_lst.c \
					start_state.c \
					ordered_array_from_stack.c \
					read_input.c

BONUS_SRC		=	checker.c

P_S_RAW			=	push_swap.c

GNL_OBJ			=	$(addprefix $(OBJ_DIR)/, $(GNL_SRC:.c=.o))
PS_OBJ_FILES	=	$(addprefix $(OBJ_DIR)/, $(PS_SRC_NAMES:.c=.o))
PS_SRC_FILES	=	$(addprefix $(SRC_DIR)/, $(addprefix	$(PS_DIR)/, $(PS_SRC_NAMES))) 
P_S_FILES		=	$(addprefix $(PS_DIR)/, $(P_S_RAW))


.PHONY: clean fclean re libft re

all: libft $(NAME)
	
bonus: all $(BONUS_NAME)

$(LIBS_DIR)/libpush_swap.a: $(PS_OBJ_FILES) 
	$(AR) $@ $(PS_OBJ_FILES)

$(LIBS_DIR)/libgnl.a : $(GNL_OBJ)
	$(AR) $@ $(GNL_OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/gnl/%.c
	@mkdir -p $(INCLUDES_DIR) $(OBJ_DIR)
	@cp -u $(SRC_DIR)/gnl/get_next_line.h $(INCLUDES_DIR)/get_next_line.h
	$(CC) $(CFLAGS) -c $< -I$(INCLUDES_DIR) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(PS_DIR)/%.c
	@mkdir -p $(INCLUDES_DIR) $(OBJ_DIR)
	@cp -u $(SRC_DIR)/$(PS_DIR)/push_swap.h $(INCLUDES_DIR)/push_swap.h
	$(CC) $(CFLAGS) -c $< -I$(INCLUDES_DIR) -o $@

$(NAME): $(LIBS_DIR)/libpush_swap.a $(P_S_RAW)
	$(CC) $(CFLAGS) $(P_S_RAW) -L./$(LIBS_DIR) -lpush_swap -lft -I$(INCLUDES_DIR) -o $(NAME)

$(BONUS_NAME): $(LIBS_DIR)/libpush_swap.a $(LIBS_DIR)/libgnl.a $(BONUS_SRC)
	$(CC) $(CFLAGS) $(BONUS_SRC) -L./$(LIBS_DIR) -lgnl -lpush_swap -lft -I$(INCLUDES_DIR) -o $(BONUS_NAME)

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
