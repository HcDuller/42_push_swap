/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_zero_at_top.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:15:55 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/25 14:16:16 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	position_zero_at_top(t_stack *stk)
{
	while (stk->stack[stk->top] != 0)
	{
		stack_shifter(stk, -1);
	}
}
