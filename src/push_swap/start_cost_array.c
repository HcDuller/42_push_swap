/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cost_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:05:19 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 22:05:45 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_cost_to_insert	**start_cost_array(int size)
{
	t_cost_to_insert	**costs;
	int					i;

	costs = ft_calloc(size, sizeof(t_cost_to_insert *));
	i = 0;
	while (i < size)
	{
		costs[i] = ft_calloc(1, sizeof(t_cost_to_insert));
		costs[i]->pa = 0;
		costs[i]->pb = 0;
		costs[i]->ra = 0;
		costs[i]->rb = 0;
		costs[i]->rra = 0;
		costs[i]->rrb = 0;
		costs[i]->rr = 0;
		costs[i]->rrr = 0;
		costs[i]->sa = 0;
		costs[i]->sb = 0;
		costs[i]->ss = 0;
		costs[i]->total_cost = 0;
		i++;
	}
	return (costs);
}
