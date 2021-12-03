/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_in_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:34:46 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 19:35:04 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	min_in_stack(t_stack *stk, int value)
{
	int	i;

	i = stk->top;
	while (i > -1)
	{
		if (stk->stack[i] < value)
			return (0);
		i--;
	}
	return (1);
}
