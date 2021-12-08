/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:20:06 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/08 19:56:40 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	destroy_state(t_p_swap *state)
{
	free(state->map);
	destroy_stack(&state->a);
	destroy_stack(&state->b);
	destroy_stack(&state->q_s_groups);
	destroy_stack(&state->keeper);
	if (state->ordered_stack != NULL)
		free(state->ordered_stack);
	if (state->operations != NULL)
		destroy_op_list(&(state->operations));
}
