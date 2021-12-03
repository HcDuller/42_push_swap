/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:01:07 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 22:12:01 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	void	execute_cost(t_p_swap *state, t_cost_to_insert *cost)
{
	while (cost->ra-- > 0)
		ra(state);
	while (cost->rb-- > 0)
		rb(state);
	while (cost->rra-- > 0)
		rra(state);
	while (cost->rrb-- > 0)
		rrb(state);
	while (cost->rr-- > 0)
		rr(state);
	while (cost->rrr-- > 0)
		rrr(state);
	while (cost->pa-- > 0)
		pa(state);
	while (cost->pb-- > 0)
		pb(state);
}

static void	execute_best_cost(t_p_swap *state, t_cost_to_insert **costs)
{
	int	best;

	best = get_best_cost_i(costs, state->b.top);
	execute_cost(state, costs[best]);
}

static void	rotate_as_needed(t_p_swap *state)
{
	int	z_index;
	int	distance;

	z_index = get_index_of(state->a.stack, state->a.size, 0);
	distance = state->a.top - z_index;
	if (distance > z_index)
	{
		while (state->a.stack[state->a.top] != 0)
			rra(state);
	}
	else
	{
		while (state->a.stack[state->a.top] != 0)
			ra(state);
	}
}

void	quick_selection(t_p_swap *state)
{
	int					top_value;
	int					section;
	t_cost_to_insert	**costs;

	build_keep_stack(state);
	push_allowed_sectors_to_b(state);
	costs = start_cost_array(state->max_value + 1);
	while (state->b.top > -1)
	{
		build_cost_array(state, costs);
		execute_best_cost(state, costs);
		clean_cost_array(costs, state->max_value);
	}
	rotate_as_needed(state);
	destroy_cost_array(costs, state->max_value + 1);
}
