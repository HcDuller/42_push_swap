/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_region_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:57:06 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/23 15:57:15 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_region_to_b(t_p_swap *state, int pivot_value)
{
	int	top_value;

	push_to_stack(&(state->q_s_groups), 0);
	while (stack_has_lesses_values_than_pivot(state->a, pivot_value))
	{
		top_value = get_stack_top(&(state->a));
		if (top_value < pivot_value)
		{
			pb(state);
			state->q_s_groups.stack[state->q_s_groups.top]++;
		}
		else
			ra(state);
	}
}
