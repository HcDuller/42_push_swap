/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:33:10 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/03 18:33:54 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_next_cost(t_cost_to_insert **costs, int top_i, int current_i)
{
	int	next;

	if (top_i < 3)
		return (0);
	if (current_i == 0)
		next = top_i;
	else
		next = current_i - 1;
	return (costs[next]->total_cost);
}
