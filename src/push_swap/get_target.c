/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:08:11 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/01 17:02:24 by hde-camp         ###   ########.fr       */
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

static int	min_in_stack(t_stack *stk, int value)
{
	int i;

	i = stk->top;
	while (i > -1)
	{
		if (stk->stack[i] < value)
			return (0);
		i--;
	}
	return (1);
}

static int	max_in_stack(t_stack *stk, int value)
{
	int i;

	i = stk->top;
	while (i > -1)
	{
		if (stk->stack[i] > value)
			return (0);
		i--;
	}
	return (1);
}

static int	min_or_max(t_stack *stk, int value)
{
	int min;
	int max;

	min = min_in_stack(stk, value);
	max = max_in_stack(stk, value);
	return (min | max);
}

int	get_target(t_stack *stk, int value, int max_value)
{
	if (min_or_max(stk, value))
		return (get_min_value(stk, max_value));
	return (get_min_above_ref(stk, value));
}
