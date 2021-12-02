/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_without_combination.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:12:31 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 14:30:02 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	*build_seq_array(int size)
{
	int	*seq;

	seq = ft_calloc(size, sizeof(int));
	size--;
	while (size > -1)
	{
		seq[size] = size;
		size--;
	}
	return (seq);
}

static int	*array_of_greater_elements(t_stack *src)
{
	int	*greater_el;
	int	i;
	int	temp_i;

	greater_el = ft_calloc(src->size, sizeof(int));
	i = src->top;
	while (i > -1)
	{
		greater_el[i] = 0;
		temp_i = i;
		while (temp_i > -1)
		{
			if (src->stack[temp_i] > src->stack[i])
				greater_el[i]++;
			temp_i--;
		}
		i--;
	}
	return (greater_el);
}

static void	start_values(int **indexes, int **greater, t_stack *src)
{
	*indexes = build_seq_array(src->size);
	*greater = array_of_greater_elements(src);
	heap_sort_by_greater(src, *indexes, *greater);
}

void	path_without_combination(t_stack *keep, t_stack *src)
{
	int	*indexes;
	int	*greater;
	int	real_value;
	int	index;
	int	c;

	start_values(&indexes, &greater, src);
	c = src->top;
	push_to_stack(keep, src->stack[c]);
	real_value = src->stack[c];
	index = indexes[c];
	c--;
	while (c > -1)
	{
		if (src->stack[c] > real_value && indexes[c] < index)
		{
			push_to_stack(keep, src->stack[c]);
			real_value = src->stack[c];
			index = indexes[c];
		}
		c--;
	}
	free(indexes);
	free(greater);
}
