/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_greater_values_in_group.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:56:24 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/23 15:56:38 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		get_greater_values_in_group(t_p_swap *state, int *first, int *second)
{
	int		n_members;
	int		top_index;
	int		i;
	t_stack	*b;

	b = &state->b;
	top_index = state->b.top;
	n_members = state->q_s_groups.stack[state->q_s_groups.top];
	*first = 0;
	*second = 0;
	i = 0;
	while (i < n_members)
	{
		if (b->stack[top_index - *first] < b->stack[top_index - i])
			*first = i;
		i++;
	}
	if (n_members > 1)
	{
		i = 0;
		if (*first == 0)
			*second = 1;
		while (i < n_members)
		{
			if (i != *first)
			{
				if (b->stack[top_index - *second] < b->stack[top_index - i])
					*second = i;
			}
			i++;
		}
		return (2);
	}
	return (1);
}
