/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_filtered_region_to_b.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:40:48 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 22:28:24 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	group_values_available(t_p_swap *state, int pivot)
{
	int		i;
	int		keep_i;
	t_stack	*stk;
	t_stack	*kp;

	i = 0;
	stk = &(state->a);
	kp = &(state->keeper);
	while (i <= stk->top)
	{
		keep_i = get_index_of(kp->stack, kp->top + 1, stk->stack[i]);
		if (stk->stack[i] < pivot && keep_i == -1)
			return (1);
		i++;
	}
	return (0);
}

void	push_filtered_region_to_b(t_p_swap *state, int pivot_value)
{
	int		top_value;
	int		keep_i;
	t_stack	*stk;

	push_to_stack(&(state->q_s_groups), 0);
	stk = &state->keeper;
	while (group_values_available(state, pivot_value))
	{
		top_value = get_stack_top(&(state->a));
		keep_i = get_index_of(stk->stack, stk->top + 1, top_value);
		if (top_value < pivot_value && keep_i == -1)
		{
			pb(state);
			state->q_s_groups.stack[state->q_s_groups.top]++;
		}
		else
			ra(state);
	}
}
