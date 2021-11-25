/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:25:20 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/25 18:59:13 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	push_to_stack(t_stack	*stack, int element)
{
	stack->top++;
	if (stack->top < stack->size)
		stack->stack[stack->top] = element;
	else
	{
		stack->top--;
		return (0);
	}
	return (1);
}
