/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort_by_greater.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:14:48 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/25 14:15:02 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	heap_sort_by_greater(t_stack *src, int *indexes, int *greater)
{
	int	last_index;
	int	iterator;
	int	pivot[2];

	last_index = src->top;
	while (last_index > -1)
	{
		pivot[0] = greater[0];
		pivot[1] = 0;
		iterator = 0;
		while (iterator <= last_index)
		{
			if (greater[iterator] > pivot[0])
			{
				pivot[0] = greater[iterator];
				pivot[1] = iterator;
			}
			iterator++;
		}
		if (pivot[1] != last_index)
		{
			swap_int_array_values(greater, pivot[1], last_index);
			swap_int_array_values(indexes, pivot[1], last_index);
			swap_int_array_values(src->stack, pivot[1], last_index);
		}
		last_index--;
	}
}
