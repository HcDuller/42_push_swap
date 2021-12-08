/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:33:14 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/08 20:33:39 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	start_state(t_p_swap *state, int size)
{
	state->a = new_stack(size);
	state->b = new_stack(size);
	state->q_s_groups = new_stack(size);
	state->keeper = new_stack(size);
	state->ordered_stack = NULL;
	state->map = ft_calloc(state->a.size / 2 + 1, sizeof(t_tuple));
	state->operations = NULL;
	state->keeper_cap = -1;
	state->moves = 0;
	state->max_value = size - 1;
}
