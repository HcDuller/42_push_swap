/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_into_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:49:13 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/23 15:49:26 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	merge_into_a(t_p_swap *state, int a_size, int b_size)
{
	int		a_i;
	int		b_i;
	int		aux;
	t_stack	*stk;

	a_i = state->b.top;
	b_i = state->b.top - a_size;
	stk = &state->b;
	while (a_size > 0 || b_size > 0)
	{
		if (a_size > 0)
		{
			if (b_size > 0)
			{
				if (stk->stack[stk->top] > stk->stack[stk->top - a_size])
				{
					pa(state);
					a_size--;
				}
				else
				{
					aux = a_size;
					while (aux > 0)
					{
						rb(state);
						aux--;
					}
					pa(state);
					b_size--;
					while (aux < a_size)
					{
						rrb(state);
						aux++;
					}
				}
			}
			else
			{
				while (a_size > 0)
				{
					pa(state);
					a_size--;
				}
			}
		}
		else
		{
			while (b_size > 0)
			{
				pa(state);
				b_size--;
			}
		}
	}
}
