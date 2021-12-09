/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:54:01 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/09 13:54:16 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <libft.h>

# define TO_B 1
# define TO_A -1

typedef enum e_operator
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_operator;

typedef struct s_cost_to_insert
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	total_cost;
}	t_cost_to_insert;

typedef struct s_op_list
{
	t_operator			operator;
	struct s_op_list	*next;
	struct s_op_list	*previous;
}	t_op_list;

typedef struct s_stack
{
	int	*stack;
	int	top;
	int	size;
}	t_stack;

typedef struct s_tuple
{
	int	a;
	int	b;
	int	direction;
}	t_tuple;

typedef struct s_p_swap
{
	t_stack		a;
	t_stack		b;
	t_stack		q_s_groups;
	t_stack		keeper;
	t_tuple		*map;
	t_op_list	*operations;
	t_list		*input;
	int			*ordered_stack;
	int			keeper_cap;
	int			moves;
	int			max_value;
}	t_p_swap;

int					is_space(char c);
int					strict_atoi(char *str, int *is_ok);
t_stack				new_stack(int size);
void				destroy_stack(t_stack *stack);
int					push_to_stack(t_stack	*stack, int element);
int					pop_from_stack(t_stack	*stack);
int					get_stack_top(t_stack *stk);
void				swap_int(int *a, int *b);
void				swap_stack_top(t_stack *stack);
void				shift_stack(t_stack *stack);
void				reverse_shift_stack(t_stack *stack);
void				stack_shifter(t_stack *stack, int direction);
void				print_stack(t_stack stack);
void				print_state(t_p_swap state);
void				replace_nl(char *str);
/**Swap "stack a" top value with its second value, if it exists.*/
void				sa(t_p_swap *state);
/**Swap "stack b" top value with its second value, if it exists.*/
void				sb(t_p_swap *state);
/**Performs sa and sb simultaneously.*/
void				ss(t_p_swap *state);
/**Pops "stack a" top value and pushed it to "stack b"*/
void				pa(t_p_swap *state);
/**Pops "stack b" top value and pushed it to "stack a"*/
void				pb(t_p_swap *state);
/**Shift up all elements of "stack a" by 1. 
 * The first element becomes the last one*/
void				ra(t_p_swap *state);
/**Shift up all elements of "stack b" by 1.
 * The first element becomes the last one*/
void				rb(t_p_swap *state);
/**Performs 'ra' and 'rb' simultaneously*/
void				rr(t_p_swap *state);
void				rra(t_p_swap *state);
void				rrb(t_p_swap *state);
void				rrr(t_p_swap *state);
t_p_swap			new_state_from_input(int argc, char *argv[]);
void				destroy_state(t_p_swap *state);
void				build_base_merge_list(t_p_swap *state);
/**sort stacks of size 2 (yeeeep, that's it)*/
void				sort_two_sized_stack(t_p_swap *state);
/**sort stacks of size 3 (yeeeep, that's it)*/
void				sort_three_sized_stack(t_p_swap *state);
void				sort_four_sized(t_p_swap *state);
void				sort_five_sized(t_p_swap *state);
t_op_list			*create_op_item(t_operator operator);
t_op_list			*combine_vertical_moves(t_op_list *any_op);
t_op_list			*add_to_op_list(t_op_list *last_operator, \
t_operator new_operator);
/**
 * @brief Revome an item from the op_list
 * 
 * @param any_operator <*t_op_list> the operator to be removed from the list
 * @return The next operator in the list if it exists. Null if it doest.
 */
t_op_list			*remove_item_from_op_list(t_op_list	*any_operator);
void				print_op_list(t_op_list	*any_op_item);
void				destroy_op_list(t_op_list **any_op_item);
int					op_list_size(t_op_list *any_op_item);
t_op_list			*get_first_op_item(t_op_list *any_op_item);
t_op_list			*get_last_op_item(t_op_list *any_op_item);
/**Returns the index of a <value> 
 * within a given <array> 
 * of size <array_size>
 * if <value> is not found, 
 * returns -1 instead. */
int					get_index_of(int *array, int array_size, int value);
/* */
void				build_keep_stack(t_p_swap *state);
void				optmize_op_list(t_op_list *any_op, t_op_list **destroy);
/**Evaluates if given stack is already sorted 
 * (top to bottom, smaller to greater)*/
int					stack_is_sorted(t_stack stk);
/** Merge group a and b from stack a to stack b
 * Params:
 * a_size, size of group a
 * b_size, size of group b
 * group must be on top of group a for this function to properly work.
*/
void				merge_into_b(t_p_swap *state, int a_size, int b_size);
void				merge_into_a(t_p_swap *state, int a_size, int b_size);
int					count_tuple_elements(t_tuple *map);
void				mutate_merge_sequence(t_tuple **input);
void				do_a_merge(t_p_swap *state);
void				merge_sort(t_p_swap *state);
t_op_list			*new_operator(t_operator op);
void				destroy_operator(t_op_list	*op_list);
t_op_list			*add_operator(t_op_list *last_op, t_operator op);
void				swap_int_array_values(int *arr, int a, int b);
void				find_resonable_sequence_in_a(t_p_swap *state);
void				copy_stack_a_to_b(t_stack *a, t_stack *b);
void				position_zero_at_top(t_stack *stk);
int					*build_array_of_indexes(t_stack *src);
int					max_in_stack(t_stack *stk, int value);
int					min_in_stack(t_stack *stk, int value);
void				heap_sort_array(int *array, int size);
void				replace_stack_values(t_p_swap *state);
int					get_min(int a, int b);
int					eval_rrb_rra(t_cost_to_insert *cost, int replace);
int					eval_ra_rrb(t_cost_to_insert *cost, int replace);
int					eval_rb_rra(t_cost_to_insert *cost, int replace);
int					eval_ra_rb(t_cost_to_insert *cost, int replace);
void				copy_cost(t_cost_to_insert *src, t_cost_to_insert *dest);
void				push_allowed_sectors_to_b(t_p_swap *state);
void				quick_selection(t_p_swap *state);
int					get_best_cost_i(t_cost_to_insert **costs, int b_top);
void				destroy_cost_array(t_cost_to_insert **costs, int size);
void				clean_cost_array(t_cost_to_insert **costs, int size);
void				build_cost_array(t_p_swap *state, t_cost_to_insert **costs);
void				rotate_as_needed(t_p_swap *state);
void				start_state(t_p_swap *state, int size);
int					*ordered_array_from_stack(t_stack	a);
t_cost_to_insert	**start_cost_array(int size);
void				read_input(t_p_swap *state, int *argc, char *argv[]);
void				destroy_lst(t_list **lst);
void				exit_error(t_p_swap *state);
void				*sliced_arg(t_p_swap *state, char *str);
void				s_handler(t_p_swap *state, char *str, int *is_ok);
void				p_handler(t_p_swap *state, char *str, int *is_ok);
void				rr_handler(t_p_swap *state, char *str, int *is_ok);
void				r_handler(t_p_swap *state, char *str, int *is_ok);
/**
 * @brief determines number of rotations<r> or reverse-rotations<rr> 
 * in order to place target value<target> on top of stack<stk>.
 * @param stk (t_stack) *stk is the stack to iterate over.
 * @param target (int)Is the value that should be placed on top of stk.
 * @param r (int *)will receive the number of rotations needed.
 * @param rr (int *)will receive the number of reverse rotations needed.
 */
void				calc_rotations(t_stack *stk, int target, int *r, int *rr);
/**
 * @brief Find the desirable target to place on top of a pre-ordered
 * stack before sending elements to it.
 * @param stk (t_stack) in which a target will be found
 * @param value (int) Value to be sent to stack <stk>
 * @param max_value (int) Greatest value in both stacks A and B	
 * @return Return the value of the target on given stack;
 */
int					get_target(t_stack *stk, int value, int max_value);
void				clean_cost_struct(t_cost_to_insert *cost);
/**
 * @brief Finds the longest ordered stack within an unordered stack,
 * it does not uses combinations, it scales linearly.
 * 
 * @param keep The stack which will receive the best elements found.
 * @param src  The origin from which elements will be searched.
 */
void				path_without_combination(t_stack *keep, t_stack *src);
void				radix_sort(t_p_swap *state);
void				push_filtered_region_to_b(t_p_swap *state, int pivot_value);
void				execute_best_cost(t_p_swap *state, \
t_cost_to_insert **costs);
int					get_next_cost(t_cost_to_insert **costs, int top_i, \
int current_i);
int					get_prev_cost(t_cost_to_insert **costs, int top_i, \
int current_i);
void				calc_insert_cost(t_p_swap *state, \
t_cost_to_insert *cost, int value);
void				heap_sort_by_greater(t_stack *src, int *indexes, \
int *greater);
#endif