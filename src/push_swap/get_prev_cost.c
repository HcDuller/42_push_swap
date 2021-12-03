/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prev_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:33:23 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/03 18:33:32 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_prev_cost(t_cost_to_insert **costs, int top_i, int current_i)
{
	int	prev;

	if (top_i < 3)
		return (0);
	if (current_i == top_i)
		prev = 0;
	else
		prev = current_i + 1;
	return (costs[prev]->total_cost);
}
