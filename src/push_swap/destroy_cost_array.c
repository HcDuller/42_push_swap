/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_cost_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:08:38 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 22:31:50 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	destroy_cost_array(t_cost_to_insert **costs, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(costs[i]);
		i++;
	}	
	free(costs);
}
