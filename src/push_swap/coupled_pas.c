/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coupled_pas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:56:47 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/25 15:13:19 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	coupled_pas(t_p_swap *state)
{
	t_op_list	*ops;
	int			indexes[3];

	ops = NULL;
	if (get_greater_values_in_group(state, &indexes[0], &indexes[1]) == 2)
	{	
		indexes[2] = 0;
		if (indexes[0] > indexes[1])
		{
			indexes[0] = indexes[0] - indexes[1] - 1;
			while (indexes[1] > 0)
			{
				rb(state);
				indexes[1]--;
				indexes[2]++;
			}
			pa(state);
			state->q_s_groups.stack[state->q_s_groups.top]--;
			while (indexes[0] > 0)
			{
				rb(state);
				indexes[0]--;
				indexes[2]++;
			}
			pa(state);
			sa(state);
			state->q_s_groups.stack[state->q_s_groups.top]--;
		}
		else
		{
			indexes[1] = indexes[1] - indexes[0] - 1;
			while (indexes[0] > 0)
			{
				rb(state);
				indexes[0]--;
				indexes[2]++;
			}
			pa(state);
			state->q_s_groups.stack[state->q_s_groups.top]--;
			while (indexes[1] > 0)
			{
				rb(state);
				indexes[1]--;
				indexes[2]++;
			}
			pa(state);
			state->q_s_groups.stack[state->q_s_groups.top]--;
		}
	}
	else
	{
		indexes[2] = indexes[0] - 1;
		while (indexes[0] > 0)
		{
			rb(state);
			indexes[0]--;
			indexes[2]++;
		}
		pa(state);
		state->q_s_groups.stack[state->q_s_groups.top]--;
	}
	while (indexes[2] > 0)
	{
		rrb(state);
		indexes[2]--;
	}
}
