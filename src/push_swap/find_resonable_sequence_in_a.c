/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_resonable_sequence_in_a.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:50:29 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/25 15:12:01 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	*build_sequential_list(int size)
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

static void	path_without_combination(t_stack *keep, t_stack *src)
{	
	int	*indexes;
	int	*greater;
	int	real_value;
	int	index;
	int	c;

	indexes = build_sequential_list(src->size);
	greater = array_of_greater_elements(src);
	heap_sort_by_greater(src, indexes, greater);
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

void	find_resonable_sequence_in_a(t_p_swap *state)
{
	t_stack	temp_keep;

	temp_keep = new_stack(state->a.size);
	position_zero_at_top(&(state->keeper));
	path_without_combination(&temp_keep, &(state->keeper));
	copy_stack_a_to_b(&temp_keep, &state->keeper);
	destroy_stack(&temp_keep);
}
