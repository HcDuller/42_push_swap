/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_into_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:48:46 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/03 14:51:27 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	push_second_group_value(t_p_swap *state, int *a_size, int *b_size)
{
	int	aux;

	aux = *a_size;
	while (aux > 0)
	{
		ra(state);
		aux -= 1;
	}
	pb(state);
	*b_size -= 1;
	while (aux < *a_size)
	{
		rra(state);
		aux += 1;
	}
}

static void	non_zero_a(t_p_swap *state, int *a_size, int *a_i, int *b_size)
{
	t_stack	*stk;

	stk = &state->a;
	if (*b_size > 0)
	{
		if (stk->stack[stk->top] < stk->stack[stk->top - *a_size])
		{
			pb(state);
			*a_i -= 1;
			*a_size -= 1;
		}
		else
		{
			push_second_group_value(state, a_size, b_size);
		}
	}
	else
	{
		while (*a_size > 0)
		{
			pb(state);
			*a_size -= 1;
		}
	}
}

void	merge_into_b(t_p_swap *state, int a_size, int b_size)
{
	int		a_i;
	int		b_i;
	t_stack	*stk;

	a_i = state->a.top;
	b_i = state->a.top - a_size;
	stk = &state->a;
	while (a_size > 0 || b_size > 0)
	{
		if (a_size > 0)
		{
			non_zero_a(state, &a_size, &a_i, &b_size);
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
