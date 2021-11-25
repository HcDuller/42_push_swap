/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_keep_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:30:47 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/25 16:46:59 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		*build_array_of_indexes(t_stack *src);
void	add_next_keep_while(t_stack *keep, t_stack *src, t_stack *temp);
void	find_best_sequence_in_a(t_p_swap *state);
void	build_keep_stack(t_p_swap *state);

static int	*build_array_of_indexes(t_stack *src)
{
	int	*indexes;
	int	i;

	indexes = ft_calloc(src->size, sizeof(int));
	i = 0;
	while (i < src->size)
	{
		indexes[i] = get_index_of(src->stack, src->size, i);
		i++;
	}
	return (indexes);
}

static int	*initialize_values(t_stack *src, int *current_k, int *next_k)
{
	int	*indexes;

	*current_k = 0;
	*next_k = 1;
	indexes = build_array_of_indexes(src);
	return (indexes);
}

void	add_next_keep_while(t_stack *keep, t_stack *src, t_stack *temp)
{
	int	i[2];
	int	current_k;
	int	next_k;
	int	*indexes;

	indexes = initialize_values(src, &current_k, &next_k);
	push_to_stack(temp, current_k);
	while (temp->stack[1] != src->top)
	{
		i[0] = indexes[current_k];
		i[1] = indexes[next_k];
		if (i[1] < i[0])
		{
			push_to_stack(temp, next_k);
			current_k = next_k;
			next_k++;
		}
		else
		{
			if (next_k + 1 < src->size)
			{
				next_k++;
			}
			else
			{
				if (temp->top > keep->top)
					copy_stack_a_to_b(temp, keep);
				next_k = get_stack_top(temp) + 1;
				pop_from_stack(temp);
				current_k = get_stack_top(temp);
			}
		}
	}
	free(indexes);
}

/** Eval combinations with loop control*/
void	find_best_sequence_in_a(t_p_swap *state)
{
	t_stack	temp_keep;
	t_stack	temp_buf;

	temp_keep = new_stack(state->a.size);
	temp_buf = new_stack(state->a.size);
	position_zero_at_top(&(state->keeper));
	add_next_keep_while(&temp_keep, &(state->keeper), &temp_buf);
	copy_stack_a_to_b(&temp_keep, &state->keeper);
	destroy_stack(&temp_keep);
	destroy_stack(&temp_buf);
}

/** Eval combinations but not really*/
void	build_keep_stack(t_p_swap *state)
{
	if (state->a.size < 100)
		find_best_sequence_in_a(state);
	else
		find_resonable_sequence_in_a(state);
}
