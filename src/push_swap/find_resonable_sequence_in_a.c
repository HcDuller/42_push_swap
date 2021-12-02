/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_resonable_sequence_in_a.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:50:29 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 14:17:49 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	find_resonable_sequence_in_a(t_p_swap *state)
{
	t_stack	temp_keep;

	temp_keep = new_stack(state->a.size);
	position_zero_at_top(&(state->keeper));
	path_without_combination(&temp_keep, &(state->keeper));
	copy_stack_a_to_b(&temp_keep, &state->keeper);
	destroy_stack(&temp_keep);
}
