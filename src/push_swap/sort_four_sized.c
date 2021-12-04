/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_sized.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:01:28 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/04 18:50:22 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//static void	el_zero_greater_el_one(t_p_swap *state, int *v)
//{
//	if (v[1] > v[2])
//	{
//		rra(state);
//		sa(state);
//	}
//	else
//	{
//		if (v[0] < v[2])
//			sa(state);
//		rra(state);
//	}
//}
//
//static void	el_zero_lesser_el_one(t_p_swap *state, int *v)
//{
//	if (v[1] > v[2])
//	{
//		if (v[0] > v[2])
//			ra(state);
//		else
//			sa(state);
//	}
//	else
//	{
//		rra(state);
//	}
//}
//
//static void	special_three_sized(t_p_swap *state)
//{
//	int	v[3];
//
//	v[0] = state->a.stack[state->a.top];
//	v[1] = state->a.stack[state->a.top - 1];
//	v[2] = state->a.stack[state->a.top - 2];
//	if (v[0] > v[1])
//		el_zero_greater_el_one(state, v);
//	else
//		el_zero_lesser_el_one(state, v);
//}

void	sort_four_sized(t_p_swap *state)
{
	int	v[4];
	t_cost_to_insert	**costs;

	v[0] = state->a.stack[state->a.top];
	v[1] = state->a.stack[state->a.top - 1];
	v[2] = state->a.stack[state->a.top - 2];
	v[3] = state->a.stack[state->a.top - 3];
	if (v[0] < v[1] && v[0] < v[2] && v[0] < v[3])
	{
		pb(state);
		sort_three_sized_stack(state);
		pa(state);
	}
	else if (v[0] > v[1] && v[0] > v[2] && v[0] > v[3])
	{
		pb(state);
		sort_three_sized_stack(state);
		pa(state);
		ra(state);
	}
	else
	{
		pb(state);
		sort_three_sized_stack(state);
		costs = start_cost_array(state->max_value + 1);
		while (state->b.top > -1)
		{
			build_cost_array(state, costs);
			execute_best_cost(state, costs);
			clean_cost_array(costs, state->max_value);
		}
		destroy_cost_array(costs, state->max_value + 1);
		//special_three_sized(state);
		//pa(state);
	}
}
