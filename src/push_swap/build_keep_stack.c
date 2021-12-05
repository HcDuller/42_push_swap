/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_keep_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:30:47 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/05 01:14:31 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		add_next_keep_while(t_stack *keep, t_stack *src, t_stack *temp);
void		find_best_sequence_in_a(t_p_swap *state);
void		build_keep_stack(t_p_swap *state);

static int	*initialize_values(t_stack *src, int *current_k, int *next_k)
{
	int	*indexes;

	*current_k = 0;
	*next_k = 1;
	indexes = build_array_of_indexes(src);
	return (indexes);
}

static void	manage_end_of_chain(t_stack *tmp, t_stack *kp, int *c_k, int *n_k)
{
	if (tmp->top > kp->top)
		copy_stack_a_to_b(tmp, kp);
	*n_k = get_stack_top(tmp) + 1;
	pop_from_stack(tmp);
	*c_k = get_stack_top(tmp);
}

void	add_next_keep_while(t_stack *keep, t_stack *src, t_stack *temp)
{
	int	current_k;
	int	next_k;
	int	*indexes;

	indexes = initialize_values(src, &current_k, &next_k);
	push_to_stack(temp, current_k);
	while (temp->stack[1] != src->top)
	{
		if (indexes[next_k] < indexes[current_k] && next_k < temp->size)
		{
			push_to_stack(temp, next_k);
			current_k = next_k;
			next_k++;
		}
		else
		{
			manage_end_of_chain(temp, keep, &current_k, &next_k);
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
