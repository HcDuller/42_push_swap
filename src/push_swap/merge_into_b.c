/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_into_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:48:46 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/23 15:48:52 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	merge_into_b(t_p_swap *state, int a_size, int b_size)
{
	int		a_i;
	int		b_i;
	int		aux;
	t_stack	*stk;

	a_i = state->a.top;
	b_i = state->a.top - a_size;
	stk = &state->a;
	while (a_size > 0 || b_size > 0)
	{
		if (a_size > 0)
		{
			if (b_size > 0)
			{
				if (stk->stack[stk->top] < stk->stack[stk->top - a_size])
				{
					pb(state);
					a_i--;
					a_size--;
				}
				else
				{
					aux = a_size;
					while (aux > 0)
					{
						ra(state);
						aux--;
					}
					pb(state);
					b_size--;
					while (aux < a_size)
					{
						rra(state);
						aux++;
					}
				}
			}
			else
			{
				while (a_size > 0)
				{
					pb(state);
					a_size--;
				}
			}
		}
		else
		{
			while (b_size > 0)
			{
				pb(state);
				b_size--;
			}
		}
	}
}
