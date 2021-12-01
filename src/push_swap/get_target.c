/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:08:11 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/30 17:00:12 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	get_min_value(t_stack *stk, int max_value)
{
	int	target;
	int	i;

	target = max_value;
	i = stk->top;
	while (i > -1)
	{
		if (stk->stack[i] < target)
			target = stk->stack[i];
		i--;
	}
	return (target);
}

static int	get_min_above_ref(t_stack *stk, int ref_value)
{
	int	target;
	int	i;

	i = stk->top;
	if (i > -1)
	{
		target = stk->stack[i];
		while (i > -1)
		{
			if (stk->stack[i] > ref_value)
			{
				target = stk->stack[i];
				break;
			}
			i--;
		}
		while (i > -1)
		{
			if (stk->stack[i] > ref_value && stk->stack[i] < target)
				target = stk->stack[i];
			i--;
		}
		return (target);
	}
	return (-1);
}

int	get_target(t_stack *stk, int value, int max_value)
{
	if (value == 0 || value == max_value)
		return (get_min_value(stk, max_value));
	return (get_min_above_ref(stk, value));
}
