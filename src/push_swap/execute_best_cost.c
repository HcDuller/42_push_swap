/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_best_cost.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:37:35 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/04 17:38:11 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	execute_cost(t_p_swap *state, t_cost_to_insert *cost)
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

void	execute_best_cost(t_p_swap *state, t_cost_to_insert **costs)
{
	int	best;

	best = get_best_cost_i(costs, state->b.top);
	execute_cost(state, costs[best]);
}