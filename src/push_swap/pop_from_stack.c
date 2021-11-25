/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_from_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:25:45 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/05 15:25:50 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		pop_from_stack(t_stack	*stack)
{
	if (stack->stack != NULL)
	{
		if (stack->top > -1)
		{
			stack->stack[stack->top] = 0;
			stack->top--;
		}
		return (1);
	}
	return (0);
}
