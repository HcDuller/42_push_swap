/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_base_merge_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:26:47 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/16 13:50:02 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	build_base_merge_list(t_p_swap *state)
{
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	if (state->a.size > 3)
	{
		while (i[1]< state->a.size)
		{
			if (state->a.size - i[1] > 3 || state->a.size - i[1] == 2)
			{
				state->map[i[0]].a = 1;
				state->map[i[0]].b = 1;
			}
			else if (state->a.size - i[1] ==  3)
			{
				state->map[0].a++;
				i[1]++;
				sort_two_sized_stack(state);
				state->map[i[0]].a = 1;
				state->map[i[0]].b = 1;
			}
			i[1] = i[1] + state->map[i[0]].a + state->map[i[0]].b;
			state->map[i[0]].direction = TO_B;
			i[0]++;
		}
	}
}
