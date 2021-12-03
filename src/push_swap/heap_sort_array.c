/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:48:48 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 20:49:06 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	heap_sort_array(int *array, int size)
{
	int	last_index;
	int	iterator;
	int	pivot[2];

	last_index = size - 1;
	while (last_index > -1)
	{
		pivot[0] = array[0];
		pivot[1] = 0;
		iterator = 0;
		while (iterator <= last_index)
		{
			if (array[iterator] > pivot[0])
			{
				pivot[0] = array[iterator];
				pivot[1] = iterator;
			}
			iterator++;
		}
		if (pivot[1] != last_index)
			swap_int_array_values(array, pivot[1], last_index);
		last_index--;
	}
}
