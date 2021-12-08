/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordered_array_from_stack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:34:14 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/08 20:35:11 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	*array_from_stack(t_stack a)
{
	int	*array;
	int	i;

	array = NULL;
	if (a.size > 0)
	{
		array = ft_calloc(a.size, sizeof(int));
		i = 0;
		while (i < a.size)
		{
			array[i] = a.stack[i];
			i++;
		}
	}
	return (array);
}

int	*ordered_array_from_stack(t_stack	a)
{
	int	*input_array;

	input_array = array_from_stack(a);
	heap_sort_array(input_array, a.size);
	return (input_array);
}
