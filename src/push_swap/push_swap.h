/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:54:01 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/18 16:49:04 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <libft.h>

# define TO_B 1
# define TO_A -1

typedef enum e_operator {PA, PB, SA, SB, SS, RA, RB, RR, RRA, RRB, RRR}	t_operator;

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
	t_tuple		*map;
	t_op_list	*operations;
	int			*ordered_stack;
	int			moves;
}	t_p_swap;

int			is_space(char c);
int			strict_atoi(char *str, int *is_ok);
t_stack		new_stack(int size);
void		destroy_stack(t_stack *stack);
int			push_to_stack(t_stack	*stack, int element);
int			pop_from_stack(t_stack	*stack);
void		swap_int(int *a, int *b);
void		swap_stack_top(t_stack *stack);
void		shift_stack(t_stack *stack);
void		reverse_shift_stack(t_stack *stack);
void		stack_shifter(t_stack *stack, int direction);
void		print_stack(t_stack stack);
void		print_state(t_p_swap state);
void		replace_nl(char *str);
/**Swap "stack a" top value with its second value, if it exists.*/
void		sa(t_p_swap *state);
/**Swap "stack b" top value with its second value, if it exists.*/
void		sb(t_p_swap *state);
/**Performs sa and sb simultaneously.*/
void		ss(t_p_swap *state);
/**Pops "stack a" top value and pushed it to "stack b"*/
void		pa(t_p_swap *state);
/**Pops "stack b" top value and pushed it to "stack a"*/
void		pb(t_p_swap *state);
/**Shift up all elements of "stack a" by 1. 
 * The first element becomes the last one*/
void		ra(t_p_swap *state);
/**Shift up all elements of "stack b" by 1.
 * The first element becomes the last one*/
void		rb(t_p_swap *state);
/**Performs 'ra' and 'rb' simultaneously*/
void		rr(t_p_swap *state);
void		rra(t_p_swap *state);
void		rrb(t_p_swap *state);
void		rrr(t_p_swap *state);
t_p_swap	new_state_from_input(int argc, char *argv[]);
void		destroy_state(t_p_swap *state);
void		build_base_merge_list(t_p_swap *state);
/**sort stacks of size 2 (yeeeep, that's it)*/
void		sort_two_sized_stack(t_p_swap *state);
t_op_list	*create_op_item(t_operator operator);
t_op_list	*add_to_op_list(t_op_list *last_operator, t_operator new_operator);
/**Remove an operation from the list.
 * returns: Next operator, if it exists, if not:
 * 			Previous Operator, if it exists, if not
 * 			NULL
*/
t_op_list	*remove_item_from_op_list(t_op_list	*any_operator);
void		print_op_list(t_op_list	*any_op_item);
void		destroy_op_list(t_op_list **any_op_item);
int			op_list_size(t_op_list *any_op_item);
t_op_list	*get_first_op_item(t_op_list *any_op_item);
t_op_list	*get_last_op_item(t_op_list *any_op_item);
#endif