/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:39:52 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/18 15:45:59 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sa(t_p_swap *state)
{
	swap_stack_top(&state->a);
	state->moves++;
	state->operations = add_to_op_list(state->operations, SA);
}

void	sb(t_p_swap *state)
{
	swap_stack_top(&state->b);
	state->moves++;
	state->operations = add_to_op_list(state->operations, SB);
}

void	ss(t_p_swap *state)
{
	swap_stack_top(&state->a);
	swap_stack_top(&state->b);
	state->moves++;
	state->operations = add_to_op_list(state->operations, SS);
}
