/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_shifter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:27:14 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/05 15:27:17 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	stack_shifter(t_stack *stack, int direction)
{
	if (stack->top > 1)
	{
		if (direction > 0)
			shift_stack(stack);
		else if (direction < 0)
			reverse_shift_stack(stack);
	}
}
