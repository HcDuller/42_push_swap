/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:57:01 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/08 18:48:40 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**Evaluates if given stack is already sorted (top to bottom, smaller to greater)*/
int	stack_is_sorted(t_stack stk)
{
	int	top;

	top = stk.top;
	while (top > 0)
	{
		if (stk.stack[top] > stk.stack[top - 1])
			return (0);
		top--;
	}
	return	(1);
}

/**sort stacks of size 2 (yeeeep, that's it)*/
void	sort_two_sized_stack(t_p_swap *state)
{
	if (state->a.stack[1] > state->a.stack[0])
		sa(state);
}

/**sort stacks of size 3 (yeeeep, that's it)*/
void	sort_three_sized_stack(t_p_swap *state)
{
	pb(state);
	if (state->a.stack[1] > state->a.stack[0])
		sa(state);
	pa(state);
	if (state->a.stack[2] > state->a.stack[0])
		ra(state);
	else if (state->a.stack[2] > state->b.stack[1])
		sa(state);
}

int	main(int argc, char *argv[])
{
	t_p_swap	state;

	state = parse_input(argc, argv);
	if (state.a.size == 2)
		sort_two_sized_stack(&state);
	else if (state.a.size == 3)
		sort_three_sized_stack(&state);
	else if (state.a.size > 3)
		ft_putstr_fd("sort stack of size greater than 3:\n", 1);
	
	ft_putstr_fd("[a]:\t", 1);
	print_stack(state.a);
	ft_putstr_fd("[b]:\t", 1);
	print_stack(state.b);
	destroy_stack(&state.a);
	destroy_stack(&state.b);
	return (0);
}
