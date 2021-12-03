/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_rrb_rra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:16:42 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 21:19:09 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	eval_rrb_rra(t_cost_to_insert *cost, int replace)
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
