/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_heap_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:57:57 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/23 15:58:04 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	quick_heap_sort(t_p_swap *state)
{
	int	last_index;
	int	pivot_index;
	int	drecrement;
	int	*ordered;

	last_index = state->a.top;
	ordered = state->ordered_stack;
	drecrement = 0.15 * state->a.size;
	pivot_index = 0;
	while (state->a.top > 1)
	{
		drecrement *= 0.9;
		if (drecrement < 10)
			drecrement = 10;
		pivot_index += drecrement;
		if (pivot_index > last_index)
			pivot_index = last_index;
		push_region_to_b(state, ordered[pivot_index]);
	}
	section_sort_from_region(state);
}
