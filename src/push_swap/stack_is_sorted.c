/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:45:05 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/23 15:45:41 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	stack_is_sorted(t_stack stk)
{
	int	top;

	top = stk.top;
	if (top == -1)
		return (0);
	while (top > 0)
	{
		if (stk.stack[top] > stk.stack[top - 1])
			return (0);
		top--;
	}
	return	(1);
}
