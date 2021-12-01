/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:03:30 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/30 19:45:37 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	void	rotations_up(t_stack *stk, int target, int *r)
{
	int	i;
	int	n;

	i = stk->top;
	n = 0;
	while (i > -1)
	{
		if (stk->stack[i] == target)
		{
			*r = n;
			return ;
		}
		i--;
		n++;
	}
	*r = -1;
}

static	void	rotations_down(t_stack *stk, int target, int *rr)
{
	int	i;

	i = 0;
	if (stk->stack[stk->top] == target)
	{
		*rr = i;
		return ;
	}
	while (i < stk->top)
	{
		if (stk->stack[i] == target)
		{
			*rr = i + 1;
			return ;
		}
		i++;
	}
	*rr = -1;
}

void	calc_rotations(t_stack *stk, int target, int *r, int *rr)
{
	rotations_up(stk, target, r);
	rotations_down(stk, target, rr);
}
