/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_cost_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:09:11 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 22:09:31 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	clean_cost_array(t_cost_to_insert **costs, int size)
{
	while (size > -1)
	{
		clean_cost_struct(costs[size]);
		size--;
	}
}
