/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:43:19 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/18 15:46:46 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ra(t_p_swap *state)
{
	shift_stack(&state->a);
	state->moves++;
	state->operations = add_to_op_list(state->operations, RA);
}

void	rb(t_p_swap *state)
{
	shift_stack(&state->b);
	state->moves++;
	state->operations = add_to_op_list(state->operations, RB);
}

void	rr(t_p_swap *state)
{
	shift_stack(&state->a);
	shift_stack(&state->b);
	state->moves++;
	state->operations = add_to_op_list(state->operations, RR);
}
