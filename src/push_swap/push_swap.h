/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:54:01 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/05 18:05:10 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

typedef struct s_stack
{
	int	*stack;
	int	top;
	int	size;
} t_stack;

typedef struct s_p_swap
{
	t_stack	a;
	t_stack	b;
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
void	replace_nl(char *str);
void	sa(t_p_swap *state);
void	sb(t_p_swap *state);
void	ss(t_p_swap *state);
void	pa(t_p_swap *state);
void	pb(t_p_swap *state);
void	ra(t_p_swap *state);
void	rb(t_p_swap *state);
void	rr(t_p_swap *state);
void	rra(t_p_swap *state);
void	rrb(t_p_swap *state);
void	rrr(t_p_swap *state);
t_p_swap	parse_input(int argc, char *argv[]);