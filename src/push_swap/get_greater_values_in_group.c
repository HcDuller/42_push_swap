/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_greater_values_in_group.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:56:24 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/25 16:20:12 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	max_within_range(t_stack *stk, int range)
{
	int	i;
	int	top_i;
	int	distance;

	i = 0;
	distance = 0;
	top_i = stk->top;
	while (i < range)
	{
		if (stk->stack[top_i - distance] < stk->stack[top_i - i])
			distance = i;
		i++;
	}
	return (distance);
}

static int	second_max_within_range(t_stack *stk, int range, int max)
{
	int	i;
	int	top_i;
	int	distance;

	i = 0;
	distance = 0;
	top_i = stk->top;
	while (i < range)
	{
		if (stk->stack[top_i - distance] < stk->stack[top_i - i])
		{
			if (stk->stack[top_i - i] != max)
				distance = i;
		}
		i++;
	}
	return (distance);
}

int	get_greater_values_in_group(t_p_swap *state, int *first, int *second)
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
	*first = max_within_range(b, n_members);
	if (n_members > 1)
	{
		*second = second_max_within_range(b, n_members, *first);
		return (2);
	}
	return (1);
}
