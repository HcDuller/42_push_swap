/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:01:07 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/04 17:37:59 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	quick_selection(t_p_swap *state)
{
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
