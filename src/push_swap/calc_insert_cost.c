/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_insert_cost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:42:47 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 21:22:23 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	void	replace_cost_with_best_opt(t_cost_to_insert *cost, int best)
{
	if (best == 0)
		eval_ra_rb(cost, 1);
	else if (best == 1)
		eval_ra_rrb(cost, 1);
	else if (best == 2)
		eval_rrb_rra(cost, 1);
	else
		eval_rb_rra(cost, 1);
}

void	calc_insert_cost(t_p_swap *state, t_cost_to_insert *cost, int value)
{
	int	target;
	int	proc_costs[4];
	int	i;
	int	best;

	target = get_target(&(state->a), value, state->max_value);
	calc_rotations(&(state->a), target, &(cost->ra), &(cost->rra));
	calc_rotations(&(state->b), value, &(cost->rb), &(cost->rrb));
	cost->pa += 1;
	cost->total_cost = cost->ra + cost->rb + cost->rra + cost->rrb + cost->pa;
	proc_costs[0] = eval_ra_rb(cost, 0);
	proc_costs[1] = eval_ra_rrb(cost, 0);
	proc_costs[2] = eval_rrb_rra(cost, 0);
	proc_costs[3] = eval_rb_rra(cost, 0);
	best = 0;
	i = 0;
	while (i < 4)
	{
		if (proc_costs[i] < proc_costs[best])
			best = i;
		i++;
	}
	replace_cost_with_best_opt(cost, best);
}
