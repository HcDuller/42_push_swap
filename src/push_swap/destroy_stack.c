/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:25:00 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/05 15:25:05 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	destroy_stack(t_stack *stack)
{
	if (stack->stack)
		free(stack->stack);
	stack->stack = NULL;
	stack->top = -1;
	stack->size = 0;
}
