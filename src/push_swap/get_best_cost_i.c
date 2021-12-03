/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_cost_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:03:14 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 22:12:30 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_best_cost_i(t_cost_to_insert **costs, int b_top)
{
	int	best;
	int	i;

	best = b_top;
	i = b_top;
	while (i > -1)
	{
		if (costs[i]->total_cost < costs[best]->total_cost)
			best = i;
		i--;
	}
	return (best);
}
