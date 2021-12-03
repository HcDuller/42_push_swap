/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_allowed_sectors_to_b.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:54:42 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 22:20:25 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	stack_has_value_above(t_stack *stk, t_stack *keeper, int value)
{
	int	i;

	i = 0;
	while (i <= stk->top)
	{
		if (stk->stack[i] <= value)
		{
			if (get_index_of(keeper->stack, keeper->size, stk->stack[i]) == -1)
				return (1);
		}
		i++;
	}
	return (0);
}

static void	push_if_allowed(t_p_swap *state, int *top_value, \
int *section, int *keep_i)
{
	t_stack	*stk;

	stk = &state->keeper;
	*top_value = get_stack_top(&(state->a));
	if (*top_value <= *section)
	{
		*keep_i = get_index_of(stk->stack, stk->top + 1, *top_value);
		if (*keep_i == -1)
			pb(state);
		else
			ra(state);
	}
	else
		ra(state);
}

void	push_allowed_sectors_to_b(t_p_swap *state)
{
	int	top_value;
	int	section;
	int	keep_i;
	int	increment;

	section = state->a.size * 0.50;
	increment = state->a.size * 0.1;
	if (increment == 0)
		increment = 1;
	while (state->a.top > state->keeper.top)
	{
		while (stack_has_value_above(&(state->a), &(state->keeper), section))
		{
			push_if_allowed(state, &top_value, &section, &keep_i);
		}
		section += increment;
	}
}
