/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_sized_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:47:51 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/05 02:06:05 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	zero_started(t_p_swap *state)
{
	t_stack	*s;

	s = &state->a;
	if (s->stack[1] > s->stack[0])
	{
		sa(state);
		ra(state);
	}
}

static void	one_started(t_p_swap *state)
{
	t_stack	*s;

	s = &state->a;
	if (s->stack[1] > s->stack[0])
		rra(state);
	else
	{
		sa(state);
	}
}

static void	two_started(t_p_swap *state)
{
	t_stack	*s;

	s = &state->a;
	if (s->stack[1] > s->stack[0])
	{
		sa(state);
		rra(state);
	}
	else
		ra(state);
}

void	sort_three_sized_stack(t_p_swap *state)
{
	int	n[3];

	n[0] = state->a.stack[state->a.top];
	n[1] = state->a.stack[state->a.top - 1];
	n[2] = state->a.stack[state->a.top - 2];
	if (n[0] < n[1] && n[0] < n[2])
		zero_started(state);
	else if (n[0] > n[1] && n[0] > n[2])
		two_started(state);
	else
		one_started(state);
}
