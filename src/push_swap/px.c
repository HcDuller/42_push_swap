/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:41:30 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/18 16:23:08 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pa(t_p_swap *state)
{
	int	temp;

	if (state->b.top > -1)
	{
		temp = state->b.stack[state->b.top];
		pop_from_stack(&state->b);
		push_to_stack(&state->a, temp);
		state->operations = add_to_op_list(state->operations, PA);
		state->moves++;
	}
}

void	pb(t_p_swap *state)
{
	int	temp;

	if (state->a.top > -1)
	{
		temp = state->a.stack[state->a.top];
		pop_from_stack(&state->a);
		push_to_stack(&state->b, temp);
		state->operations = add_to_op_list(state->operations, PB);
		state->moves++;
	}
}
