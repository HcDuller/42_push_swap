/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:37:31 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/04 12:48:01 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ten_power(int power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (10);
	return (10 * ten_power(power - 1));
}

static void	push_to_b(t_p_swap *state, int pow)
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
			if ((top_v / ten_power(pow)) % 10 == key)
				pb(state);
			else
				ra(state);
			max_loop--;
		}
		key++;
	}
}

static void	push_to_a(t_p_swap *state, int pow)
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
			if ((top_v / ten_power(pow)) % 10 == key)
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
	push_to_b(state, 0);
	push_to_a(state, 1);
}
