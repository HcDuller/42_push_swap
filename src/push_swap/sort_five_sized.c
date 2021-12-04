/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_sized.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:25:58 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/04 18:27:03 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//static void	send_zero_one(t_p_swap *state)
//{
//	while (state->a.top > 2)
//	{
//		if (state->a.stack[state->a.top] <= 1)
//			pb(state);
//		else
//			ra(state);
//	}
//}

void	sort_five_sized(t_p_swap *state)
{
	t_cost_to_insert	**costs;

	//send_zero_one(state);
	pb(state);
	//pb(state);
	//sort_three_sized_stack(state);
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
