/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:26:26 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/10 14:44:27 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_stack_top(t_stack *stack)
{
	if (stack->size > 1 && stack->top > 0)
	{
		swap_int(&stack->stack[stack->top], &stack->stack[stack->top - 1]);
	}
}
