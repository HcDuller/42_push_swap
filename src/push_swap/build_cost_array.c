/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cost_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:09:42 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 22:09:55 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	build_cost_array(t_p_swap *state, t_cost_to_insert **costs)
{
	int	i;

	i = state->b.top;
	while (i > -1)
	{
		calc_insert_cost(state, costs[i], state->b.stack[i]);
		i--;
	}
}
