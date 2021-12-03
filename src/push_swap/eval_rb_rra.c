/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_rb_rra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:16:45 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 21:22:04 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	eval_rb_rra(t_cost_to_insert *cost, int replace)
{
	t_cost_to_insert	temp_cost;
	int					tot;

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
