/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_sized.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:01:28 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/04 23:07:39 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	start_values(t_p_swap *state, int *values)
{
	values[0] = state->a.stack[state->a.top];
	values[1] = state->a.stack[state->a.top - 1];
	values[2] = state->a.stack[state->a.top - 2];
	values[3] = state->a.stack[state->a.top - 3];
}

static void	execute_b_to_a(t_p_swap *state)
{
	t_cost_to_insert	**costs;

	costs = start_cost_array(state->max_value + 1);
	while (state->b.top > -1)
	{
		build_cost_array(state, costs);
		execute_best_cost(state, costs);
		clean_cost_array(costs, state->max_value);
	}
	destroy_cost_array(costs, state->max_value + 1);
}

void	sort_four_sized(t_p_swap *state)
{
	int					v[4];

	start_values(state, v);
	pb(state);
	if (v[0] < v[1] && v[0] < v[2] && v[0] < v[3])
	{
		sort_three_sized_stack(state);
		pa(state);
	}
	else if (v[0] > v[1] && v[0] > v[2] && v[0] > v[3])
	{
		sort_three_sized_stack(state);
		pa(state);
		ra(state);
	}
	else
	{
		sort_three_sized_stack(state);
		execute_b_to_a(state);
	}
}
