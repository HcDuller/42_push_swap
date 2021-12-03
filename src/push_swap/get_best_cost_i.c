/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_cost_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:03:14 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/03 18:33:42 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	add_index_to_list(int *i_list, int new_value)
{
	int	i;

	i = 0;
	while (i_list[i] != -1)
		i++;
	i_list[i] = new_value;
	i_list[i + 1] = -1;
}

void	clean_list(int *i_list, int size)
{
	ft_bzero(i_list, size);
	i_list[0] = -1;
}

static int	best_sum_from_list(t_cost_to_insert **costs, int top_i, int *evens)
{
	int	i;
	int	best;
	int	sums[2];

	best = 0;
	sums[0] = get_next_cost(costs, top_i, evens[0]);
	sums[0] += get_prev_cost(costs, top_i, evens[0]);
	i = 1;
	while (evens[i] != -1)
	{
		sums[1] = get_next_cost(costs, top_i, evens[i]);
		sums[1] += get_prev_cost(costs, top_i, evens[i]);
		if (sums[1] < sums[0])
		{
			sums[0] = sums[1];
			best = i;
		}
		i++;
	}
	return (evens[best]);
}

int	get_best_cost_i(t_cost_to_insert **costs, int b_top)
{
	int	best;
	int	i;
	int	*even;

	best = b_top;
	even = ft_calloc(b_top + 2, sizeof(int));
	even[0] = -1;
	i = b_top;
	while (i > -1)
	{
		if (costs[i]->total_cost <= costs[best]->total_cost)
		{
			if (costs[i]->total_cost < costs[best]->total_cost)
			{
				clean_list(even, b_top + 1);
				best = i;
			}
			add_index_to_list(even, i);
		}
		i--;
	}
	best = best_sum_from_list(costs, b_top, even);
	free(even);
	return (best);
}
