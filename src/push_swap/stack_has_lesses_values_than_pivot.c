/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_has_lesses_values_than_pivot.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:52:22 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/25 17:46:35 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	stack_has_lesses_values_than_pivot(t_stack stk, int pivot)
{
	int	i;

	i = 0;
	while (i <= stk.top)
	{
		if (stk.stack[i] < pivot)
			return (1);
		i++;
	}
	return (0);
}
