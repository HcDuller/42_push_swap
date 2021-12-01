/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_insert_cost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:42:47 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/30 21:18:40 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int get_min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

static	void copy_cost(t_cost_to_insert *src, t_cost_to_insert *dest)
{
	dest->pa = src->pa;
	dest->pb = src->pb;
	dest->ra = src->ra;
	dest->rb = src->rb;
	dest->rra = src->rra;
	dest->rrb = src->rrb;
	dest->rr = src->rr;
	dest->rrr = src->rrr;
	dest->sa = src->sa;
	dest->sb = src->sb;
	dest->ss = src->ss;
	dest->total_cost = src->total_cost;
}

static	int eval_ra_rb(t_cost_to_insert *cost, int replace)
{
	t_cost_to_insert	temp_cost;
	int					temp_value;
	int					tot;

	clean_cost_struct(&temp_cost);
	tot = 0;
	temp_value = get_min(cost->ra, cost->rb);
	temp_cost.ra = cost->ra - temp_value;
	temp_cost.rb = cost->rb - temp_value;
	temp_cost.rr = temp_value;
	temp_cost.pb = cost->pb;
	temp_cost.pa = cost->pa;
	tot += temp_cost.ra + temp_cost.rb + temp_cost.rr;
	tot += temp_cost.pa + temp_cost.pb;
	temp_cost.total_cost = tot;
	if (replace == 1)
		copy_cost(&(temp_cost), cost);
	return (tot);
}

static	int eval_ra_rrb(t_cost_to_insert *cost, int replace)
{
	t_cost_to_insert	temp_cost;
	int	tot;

	tot = 0;
	tot += cost->ra;
	tot += cost->rrb;
	tot += cost->pa;
	tot += cost->pb;
	clean_cost_struct(&temp_cost);
	temp_cost.ra = cost->ra;
	temp_cost.rrb = cost->rrb;
	temp_cost.pa = cost->pa;
	temp_cost.pb = cost->pb;
	temp_cost.total_cost = tot;
	if (replace == 1)
		copy_cost(&(temp_cost), cost);
	return (tot);
}

static	int eval_rrb_rra(t_cost_to_insert *cost, int replace)
{
	t_cost_to_insert	temp_cost;
	int					temp_value;
	int					tot;

	clean_cost_struct(&temp_cost);
	tot = 0;
	temp_value = get_min(cost->rra, cost->rrb);
	temp_cost.rra = cost->rra - temp_value;
	temp_cost.rrb = cost->rrb - temp_value;
	temp_cost.rrr = temp_value;
	temp_cost.pb = cost->pb;
	temp_cost.pa = cost->pa;
	tot += temp_cost.rra + temp_cost.rrb + temp_cost.rrr;
	tot += temp_cost.pa + temp_cost.pb;
	temp_cost.total_cost = tot;
	if (replace == 1)
		copy_cost(&(temp_cost), cost);
	return (tot);
}

static	int eval_rb_rra(t_cost_to_insert *cost, int replace)
{
	t_cost_to_insert	temp_cost;
	int	tot;

	tot = 0;
	tot += cost->rb;
	tot += cost->rra;
	tot += cost->pa;
	tot += cost->pb;
	clean_cost_struct(&temp_cost);
	temp_cost.rb = cost->rb;
	temp_cost.rra = cost->rra;
	temp_cost.pa = cost->pa;
	temp_cost.pb = cost->pb;
	temp_cost.total_cost = tot;
	if (replace == 1)
		copy_cost(&(temp_cost), cost);
	return (tot);
}

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
	proc_costs[0] = eval_ra_rb(cost, 0);
	proc_costs[1] = eval_ra_rrb(cost, 0);
	proc_costs[2] = eval_rrb_rra(cost, 0);
	proc_costs[3] = eval_rb_rra(cost, 0);
	best = 0;
	i = 0;
	while (i < 4)
	{
		if (proc_costs[i] < proc_costs[best])
			best = 1;
		i++;
	}
	replace_cost_with_best_opt(cost, best);
}
