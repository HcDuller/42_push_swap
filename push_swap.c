/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:57:01 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/09 18:45:40 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**Evaluates if given stack is already sorted (top to bottom, smaller to greater)*/
int	stack_is_sorted(t_stack stk)
{
	int	top;

	top = stk.top;
	if (top == -1)
		return (0);
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
/** Merge group a and b from stack a to stack b
 * Params:
 * a_size, size of group a
 * b_size, size of group b
 * group must is on top on group b for this function to properly work.
*/
void	merge_into_b(t_p_swap *state, int a_size, int b_size)
{
	int		a_i;
	int		b_i;
	int		aux;
	t_stack	*stk;

	a_i = state->a.top;
	b_i = state->a.top - a_size;
	stk = &state->a;
	while (a_size > 0 || b_size > 0)
	{
		if (a_size > 0)
		{
			if (b_size > 0)
			{
				if (stk->stack[stk->top] < stk->stack[stk->top - a_size])
				{
					pb(state);
					print_state(*state);
					a_i--;
					a_size--;
				}
				else
				{
					aux = a_size;
					while (aux > 0)
					{
						ra(state);
						print_state(*state);
						aux--;
					}
					pb(state);
					print_state(*state);
					b_size--;
					while (aux < a_size)
					{
						rra(state);
						print_state(*state);
						aux++;
					}
				}
			}
			else
			{
				while (a_size > 0)
				{
					pb(state);
					print_state(*state);
					a_size--;
				}
			}
		}
		else
		{
			while (b_size > 0)
			{
				pb(state);
				print_state(*state);
				b_size--;
			}
		}
	}
}
void	merge_into_a(t_p_swap *state, int a_size, int b_size)
{
	int		a_i;
	int		b_i;
	int		aux;
	t_stack	*stk;

	a_i = state->b.top;
	b_i = state->b.top - a_size;
	stk = &state->b;
	while (a_size > 0 || b_size > 0)
	{
		if (a_size > 0)
		{
			if (b_size > 0)
			{
				if (stk->stack[stk->top] > stk->stack[stk->top - a_size])
				{
					pa(state);
					print_state(*state);
					a_size--;
				}
				else
				{
					aux = a_size;
					while (aux > 0)
					{
						rb(state);
						print_state(*state);
						aux--;
					}
					pa(state);
					print_state(*state);
					b_size--;
					while (aux < a_size)
					{
						rrb(state);
						print_state(*state);
						aux++;
					}
				}
			}
			else
			{
				while (a_size > 0)
				{
					pa(state);
					print_state(*state);
					a_size--;
				}
			}
		}
		else
		{
			while (b_size > 0)
			{
				pa(state);
				print_state(*state);
				b_size--;
			}
		}
	}
}
int	main(int argc, char *argv[])
{
	t_p_swap	state;
	t_tuple		*tuples;
	int			i[2];

	state = parse_input(argc, argv);
		ft_putstr_fd("Start\n", 1);
	print_state(state);
	if (state.a.size == 2)
		sort_two_sized_stack(&state);
	else if (state.a.size == 3)
		sort_three_sized_stack(&state);
	else if (state.a.size > 3)
	{
		tuples = ft_calloc(state.a.size / 2 + 1, sizeof(t_tuple));
		i[0] = 0;
		i[1] = 0;
		while (i[1]< state.a.size)
		{
			if (state.a.size - i[1] > 3 || state.a.size - i[1] == 2)
			{
				tuples[i[0]].a = 1;
				tuples[i[0]].b = 1;
			}
			else if (state.a.size - i[1] ==  3)
			{
				tuples[i[0]].a = 1;
				tuples[i[0]].b = 2;
			}
			i[1] = i[1] + tuples[i[0]].a + tuples[i[0]].b;
			i[0]++;
		}
		i[0] = 0;
		while (tuples[i[0]].a != 0)
		{
			merge_into_b(&state,tuples[i[0]].a,tuples[i[0]].b);
			i[0]++;
		}
	}
	print_state(state);
	destroy_stack(&state.a);
	destroy_stack(&state.b);
	return (0);
}
