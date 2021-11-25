/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:43:25 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/18 15:47:02 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rra(t_p_swap *state)
{
	reverse_shift_stack(&state->a);
	state->moves++;
	state->operations = add_to_op_list(state->operations, RRA);
}

void	rrb(t_p_swap *state)
{
	reverse_shift_stack(&state->b);
	state->moves++;
	state->operations = add_to_op_list(state->operations, RRB);
}

void	rrr(t_p_swap *state)
{
	reverse_shift_stack(&state->a);
	reverse_shift_stack(&state->b);
	state->moves++;
	state->operations = add_to_op_list(state->operations, RRR);
}
