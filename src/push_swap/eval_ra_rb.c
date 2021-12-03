/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_ra_rb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:16:49 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 21:19:58 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	eval_ra_rb(t_cost_to_insert *cost, int replace)
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
