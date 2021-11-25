/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section_sort_from_region.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:57:25 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/23 15:57:32 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	section_sort_from_region(t_p_swap *state)
{
	while (state->q_s_groups.top > -1)
	{
		while (state->q_s_groups.stack[state->q_s_groups.top] != 0)
		{
			coupled_pas(state);
		}
		pop_from_stack(&state->q_s_groups);
	}
}
