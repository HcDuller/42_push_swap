/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_sized.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:25:58 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/05 02:05:54 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_five_sized(t_p_swap *state)
{
	t_cost_to_insert	**costs;

	pb(state);
	sort_four_sized(state);
	costs = start_cost_array(state->max_value + 1);
	while (state->b.top > -1)
	{
		build_cost_array(state, costs);
		execute_best_cost(state, costs);
		clean_cost_array(costs, state->max_value);
	}
	destroy_cost_array(costs, state->max_value + 1);
}
