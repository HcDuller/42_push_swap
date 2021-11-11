/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:54:01 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/10 19:56:13 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

#define TO_B 1
#define TO_A -1

typedef struct s_stack
{
	int	*stack;
	int	top;
	int	size;
} t_stack;

typedef	struct s_tuple
{
	int	a;
	int	b;
	int direction;
} t_tuple;

typedef struct s_p_swap
{
	t_stack	a;
	t_stack	b;
	t_tuple	*map;
	int		moves;
} t_p_swap;


int		is_space(char c);
int		strict_atoi(char *str, int *is_ok);
t_stack	new_stack(int size);
void	destroy_stack(t_stack *stack);
int		push_to_stack(t_stack	*stack, int element);
int		pop_from_stack(t_stack	*stack);
void	swap_int(int *a, int *b);
void	swap_stack_top(t_stack *stack);
void	shift_stack(t_stack *stack);
void	reverse_shift_stack(t_stack *stack);
void	stack_shifter(t_stack *stack, int direction);
void	print_stack(t_stack stack);
void	print_state(t_p_swap state);
void	replace_nl(char *str);
/**Swap "stack a" top value with its second value, if it exists.*/
void	sa(t_p_swap *state);
/**Swap "stack b" top value with its second value, if it exists.*/
void	sb(t_p_swap *state);
/**Performs sa and sb simultaneously.*/
void	ss(t_p_swap *state);
/**Pops "stack a" top value and pushed it to "stack b"*/
void	pa(t_p_swap *state);
/**Pops "stack b" top value and pushed it to "stack a"*/
void	pb(t_p_swap *state);
/**Shift up all elements of "stack a" by 1. The first element becomes the last one*/
void	ra(t_p_swap *state);
/**Shift up all elements of "stack b" by 1. The first element becomes the last one*/
void	rb(t_p_swap *state);
/**Performs 'ra' and 'rb' simultaneously*/
void	rr(t_p_swap *state);
void	rra(t_p_swap *state);
void	rrb(t_p_swap *state);
void	rrr(t_p_swap *state);
t_p_swap	new_state_from_input(int argc, char *argv[]);
void	destroy_state(t_p_swap *state);
/**sort stacks of size 2 (yeeeep, that's it)*/
void	sort_two_sized_stack(t_p_swap *state);