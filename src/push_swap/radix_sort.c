/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:37:31 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/03 19:18:28 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	push_to_b(t_p_swap *state)
{
	int	key;
	int	top_v;
	int	max_loop;

	key = 0;
	while (key < 10)
	{
		max_loop = state->a.top;
		while (max_loop > -1)
		{
			top_v = get_stack_top(&(state->a));
			if (top_v % 10 == key)
				pb(state);
			else
				ra(state);
			max_loop--;
		}
		key++;
	}
}

static void	push_to_a(t_p_swap *state)
{
	int	key;
	int	top_v;
	int	max_loop;

	key = 9;
	while (key > -1)
	{
		max_loop = state->b.top;
		while (max_loop > -1)
		{
			top_v = get_stack_top(&(state->b));
			if (top_v / 10 == key)
				pa(state);
			else
				rb(state);
			max_loop--;
		}
		key--;
	}
}

void	radix_sort(t_p_swap *state)
{
	push_to_b(state);
	push_to_a(state);
}
