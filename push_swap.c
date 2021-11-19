/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:57:01 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/18 23:35:53 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**Evaluates if given stack is already sorted (top to bottom, smaller to greater)*/

static void	optmize_op_list(t_op_list *any_op);

int	stack_is_sorted(t_stack stk)
{
	int	top;

	top = stk.top;
	if (top == -1)
		return (0);
	while (top > 0)
	{
		if (stk.stack[top] > stk.stack[top - 1])
			return (0);
		top--;
	}
	return	(1);
}
/**sort stacks of size 3 (yeeeep, that's it)*/
void	sort_three_sized_stack(t_p_swap *state)
{
	pb(state);
	if (state->a.stack[1] > state->a.stack[0])
		sa(state);
	pa(state);
	if (state->a.stack[2] > state->a.stack[0])
		ra(state);
	else if (state->a.stack[2] > state->b.stack[1])
		sa(state);
}
/** Merge group a and b from stack a to stack b
 * Params:
 * a_size, size of group a
 * b_size, size of group b
 * group must is on top on group b for this function to properly work.
*/
void	merge_into_b(t_p_swap *state, int a_size, int b_size)
{
	int		a_i;
	int		b_i;
	int		aux;
	t_stack	*stk;

	a_i = state->a.top;
	b_i = state->a.top - a_size;
	stk = &state->a;
	while (a_size > 0 || b_size > 0)
	{
		if (a_size > 0)
		{
			if (b_size > 0)
			{
				if (stk->stack[stk->top] < stk->stack[stk->top - a_size])
				{
					pb(state);
					a_i--;
					a_size--;
				}
				else
				{
					aux = a_size;
					while (aux > 0)
					{
						ra(state);
						aux--;
					}
					pb(state);
					b_size--;
					while (aux < a_size)
					{
						rra(state);
						aux++;
					}
				}
			}
			else
			{
				while (a_size > 0)
				{
					pb(state);
					a_size--;
				}
			}
		}
		else
		{
			while (b_size > 0)
			{
				pb(state);
				b_size--;
			}
		}
	}
}
void	merge_into_a(t_p_swap *state, int a_size, int b_size)
{
	int		a_i;
	int		b_i;
	int		aux;
	t_stack	*stk;

	a_i = state->b.top;
	b_i = state->b.top - a_size;
	stk = &state->b;
	while (a_size > 0 || b_size > 0)
	{
		if (a_size > 0)
		{
			if (b_size > 0)
			{
				if (stk->stack[stk->top] > stk->stack[stk->top - a_size])
				{
					pa(state);
					a_size--;
				}
				else
				{
					aux = a_size;
					while (aux > 0)
					{
						rb(state);
						aux--;
					}
					pa(state);
					b_size--;
					while (aux < a_size)
					{
						rrb(state);
						aux++;
					}
				}
			}
			else
			{
				while (a_size > 0)
				{
					pa(state);
					a_size--;
				}
			}
		}
		else
		{
			while (b_size > 0)
			{
				pa(state);
				b_size--;
			}
		}
	}
}

int	count_tuple_elements(t_tuple *map)
{
	int	total_elements;
	int	index;

	index = 0;
	total_elements = 0;
	map = NULL;
	return total_elements;
}
void	mutate_merge_sequence(t_tuple **input)
{
	int		total_elements;
	int		i_index;
	int		n_index;
	int		direction;
	t_tuple	*new_tuple;

	total_elements = 0;
	i_index = 0;
	direction = (*input)[0].direction * -1;
	while ((*input)[i_index].a != 0)
	{
		total_elements += (*input)[i_index].a;
		total_elements += (*input)[i_index].b;
		i_index++;
	}
	new_tuple = ft_calloc(i_index / 2 + i_index % 2  + 1, sizeof(t_tuple));
	i_index--;
	n_index = 0;
	while (total_elements > 0)
	{
		new_tuple[n_index].direction = direction;
		if (i_index < 1)
		{
			new_tuple[n_index].a = (*input)[i_index].a + (*input)[i_index].b;
			new_tuple[n_index].b = 0;
			total_elements -= (new_tuple[n_index].a + new_tuple[n_index].b);
			i_index -= 1;
		}
		else
		{
			new_tuple[n_index].a = (*input)[i_index].a + (*input)[i_index].b;
			new_tuple[n_index].b = (*input)[i_index - 1].a + (*input)[i_index - 1].b;
			total_elements -= (new_tuple[n_index].a + new_tuple[n_index].b);
			i_index -= 2;
		}
		n_index++;
	}
	free(*input);
	*input = new_tuple;
}

void	do_a_merge(t_p_swap *state)
{
	int	i;

	i = 0;
	if (state->map->direction == TO_B)
	{
		while (state->map[i].a != 0)
		{
			merge_into_b(state, state->map[i].a, state->map[i].b);
			i++;
		}
	}
	else if (state->map->direction == TO_A)
	{
		while (state->map[i].a != 0)
		{
			merge_into_a(state, state->map[i].a, state->map[i].b);
			i++;
		}
	}
}

void	merge_sort(t_p_swap *state)
{
	build_base_merge_list(state);
	while (!stack_is_sorted(state->a) || state->b.top > -1)
	{
		do_a_merge(state);
		mutate_merge_sequence(&state->map);
	}
}

int		stack_has_lesses_values_than_pivot(t_stack stk, int pivot)
{
	int	i;

	i = 0;
	while (i <= stk.top)
	{
		if (stk.stack[i] < pivot)
			return (1);
		i++;
	}
	return (0);
}

t_op_list	*new_operator(t_operator op)
{
	t_op_list	*new;

	new = NULL;
	new = ft_calloc(1, sizeof(t_op_list));
	if (new != NULL)
	{
		new->operator = op;
		new->next = NULL;
		new->previous = NULL;
	}
	return (new);
}

void		destroy_operator(t_op_list	*op_list)
{
	if (op_list != NULL)
		free(op_list);
}

t_op_list	*add_operator(t_op_list *last_op, t_operator op)
{
	t_op_list	*new;

	new = new_operator(op);
	if (new)
	{
		if (last_op)
		{
			last_op->next = new;
			new->previous = last_op;
		}
	}
	return (new);
}

int		get_greater_values_in_group(t_p_swap *state, int *first, int *second)
{
	int		n_members;
	int		top_index;
	int		i;
	t_stack	*b;

	b = &state->b;
	top_index = state->b.top;
	n_members = state->q_s_groups.stack[state->q_s_groups.top];
	*first = 0;
	*second = 0;
	i = 0;
	while (i < n_members)
	{
		if (b->stack[top_index - *first] < b->stack[top_index - i])
			*first = i;
		i++;
	}
	if (n_members > 1)
	{
		i = 0;
		if (*first == 0)
			*second = 1;
		while (i < n_members)
		{
			if (i != *first)
			{
				if (b->stack[top_index - *second] < b->stack[top_index - i])
					*second = i;
			}
			i++;
		}
		return (2);
	}
	return (1);
}

void	coupled_pbs(t_p_swap *state)
{
	t_op_list	*ops;
	int			indexes[3];

	ops = NULL;
	if (get_greater_values_in_group(state, &indexes[0], &indexes[1]) == 2)
	{	
		indexes[2] = 0;	
		if (indexes[0] > indexes[1])
		{
			indexes[0] = indexes[0] - indexes[1] - 1;
			while (indexes[1] > 0)
			{
				rb(state);
				indexes[1]--;
				indexes[2]++;
			}
			pa(state);
			state->q_s_groups.stack[state->q_s_groups.top]--;
			while (indexes[0] > 0)
			{
				rb(state);
				indexes[0]--;
				indexes[2]++;
			}
			pa(state);
			sa(state);
			state->q_s_groups.stack[state->q_s_groups.top]--;
		}
		else
		{
			indexes[1] = indexes[1] - indexes[0] - 1;
			while (indexes[0] > 0)
			{
				rb(state);
				indexes[0]--;
				indexes[2]++;
			}
			pa(state);
			state->q_s_groups.stack[state->q_s_groups.top]--;
			while (indexes[1] > 0)
			{
				rb(state);
				indexes[1]--;
				indexes[2]++;
			}
			pa(state);
			state->q_s_groups.stack[state->q_s_groups.top]--;
		}
		
	}
	else
	{
		indexes[2] = indexes[0] - 1;
		while (indexes[0] > 0)
		{
			rb(state);
			indexes[0]--;
			indexes[2]++;
		}
		pa(state);
		state->q_s_groups.stack[state->q_s_groups.top]--;
	}
	while (indexes[2] > 0)
	{
		rrb(state);
		indexes[2]--;
	}
}

void	optmize_op_list(t_op_list *any_op)
{

	while (any_op->previous != NULL)
	{
		any_op = any_op->previous;
	}
	while (any_op->next != NULL)
	{
		if ((any_op->operator == RA && any_op->next->operator == RRA) || \
		(any_op->operator == RRA && any_op->next->operator == RA) || \
		(any_op->operator == RB && any_op->next->operator == RRB) || \
		(any_op->operator == RRB && any_op->next->operator == RB) \
		)
		{
			any_op = remove_item_from_op_list(any_op);
			any_op = remove_item_from_op_list(any_op);
			any_op = any_op->previous;
		}
		else
			any_op = any_op->next;
	}
}

void	quick_heap_sort(t_p_swap *state)
{
	int	last_index;
	int	pivot_index;
	int	drecrement;
	int	stk_top;
	int	*ordered;

	last_index = state->a.top;
	ordered = state->ordered_stack;
	drecrement = 0.15 * state->a.size;
	pivot_index = 0;
	while (state->a.top > 1)
	{
		drecrement *= 0.9;
		if (drecrement < 10)
			drecrement = 10;
		pivot_index += drecrement;
		if (pivot_index > last_index)
			pivot_index = last_index;
		push_to_stack(&(state->q_s_groups), 0);
		while (stack_has_lesses_values_than_pivot(state->a, ordered[pivot_index]))
		{
			stk_top = (state->a.stack)[state->a.top];
			if (stk_top <= ordered[pivot_index] && stk_top < ordered[last_index])
			{
				pb(state);
				state->q_s_groups.stack[state->q_s_groups.top]++;
				//pequena "pre-ordenacao em b" ajudou POUQUISSIMO
				if (state->b.top > 0)
				{
					if (state->b.stack[state->b.top] < state->b.stack[state->b.top - 1])
					sb(state);
				}
			}
			else
			{
				ra(state);
			}
			if (state->a.top == 1)
			{
				if (state->a.stack[0] < state->a.stack[1])
					sa(state);
			}
		}
	}
	while (state->q_s_groups.top > -1)
	{
		while (state->q_s_groups.stack[state->q_s_groups.top] != 0)
		{
			coupled_pbs(state);
		}
		pop_from_stack(&state->q_s_groups);
	}
}

int	main(int argc, char *argv[])
{
	t_p_swap	state;

	state = new_state_from_input(argc, argv);
	if (state.a.size == 2)
		sort_two_sized_stack(&state);
	else if (state.a.size == 3)
		sort_three_sized_stack(&state);
	else if (state.a.size > 3)
	{
		//merge_sort(&state);
		quick_heap_sort(&state);
	}
	optmize_op_list(state.operations);
	print_op_list(state.operations);
	destroy_state(&state);
	return (0);
}
