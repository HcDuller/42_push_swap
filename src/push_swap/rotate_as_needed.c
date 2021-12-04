/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_as_needed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:05:51 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/04 17:06:06 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate_as_needed(t_p_swap *state)
{
	int	z_index;
	int	distance;

	z_index = get_index_of(state->a.stack, state->a.size, 0);
	distance = state->a.top - z_index;
	if (distance > z_index)
	{
		while (state->a.stack[state->a.top] != 0)
			rra(state);
	}
	else
	{
		while (state->a.stack[state->a.top] != 0)
			ra(state);
	}
}
