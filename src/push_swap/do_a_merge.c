/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_a_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:51:39 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/23 15:51:46 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	do_a_merge(t_p_swap *state)
{
	int	i;

	i = 0;
	if (state->map->direction == TO_B)
	{
		while (state->map[i].a != 0)
		{
			merge_into_b(state, state->map[i].a, state->map[i].b);
			i++;
		}
	}
	else if (state->map->direction == TO_A)
	{
		while (state->map[i].a != 0)
		{
			merge_into_a(state, state->map[i].a, state->map[i].b);
			i++;
		}
	}
}
