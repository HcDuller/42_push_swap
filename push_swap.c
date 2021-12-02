/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:57:01 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 16:38:47 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		keep_pushing(t_p_swap *state)
{
	int	i;

	i = 0;
	while (i < state->a.size)
	{
		if (get_index_of(state->keeper.stack, state->keeper.size, state->a.stack[i]) == -1)
			return (1);
		i++;
	}	
	return (0);
}

int		group_values_available(t_p_swap *state, int pivot)
{
	int	i;
	int	keep_i;
	t_stack	*stk;

	i = 0;
	stk = &(state->a);
	while (i <= stk->top)
	{
		keep_i = get_index_of(state->keeper.stack, state->keeper.top + 1, stk->stack[i]);
		if (stk->stack[i] < pivot && keep_i == -1)
			return (1);
		i++;
	}
	
	return (0);
}

void	push_filtered_region_to_b(t_p_swap *state, int pivot_value)
{
	int	top_value;
	int	keep_i;

	push_to_stack(&(state->q_s_groups), 0);
	while (group_values_available(state, pivot_value))
	{
		top_value = get_stack_top(&(state->a));
		keep_i = get_index_of(state->keeper.stack, state->keeper.top + 1, top_value);
		if (top_value < pivot_value && keep_i == -1)
		{
			pb(state);
			state->q_s_groups.stack[state->q_s_groups.top]++;
		}
		else
			ra(state);
	}
}

static t_cost_to_insert	**start_cost_array(int size)
{
	t_cost_to_insert	**costs;
	int					i;

	costs = ft_calloc(size, sizeof(t_cost_to_insert *));
	i = 0;
	while (i < size)
	{
		costs[i] = ft_calloc(1, sizeof(t_cost_to_insert));
		costs[i]->pa = 0;
		costs[i]->pb = 0;
		costs[i]->ra = 0;
		costs[i]->rb = 0;
		costs[i]->rra = 0;
		costs[i]->rrb = 0;
		costs[i]->rr = 0;
		costs[i]->rrr = 0;
		costs[i]->sa = 0;
		costs[i]->sb = 0;
		costs[i]->ss = 0;
		costs[i]->total_cost = 0;
		i++;
	}
	return (costs);
}

static void	destroy_cost_array(t_cost_to_insert **costs, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(costs[i]);
		i++;
	}	
	free(costs);
}

static void	clean_cost_array(t_cost_to_insert **costs, int size)
{
	while (size > -1)
	{
		clean_cost_struct(costs[size]);
		size--;
	}
}

static void	build_cost_array(t_p_swap *state, t_cost_to_insert **costs)
{
	int	i;

	i = state->b.top;
	while (i > -1)
	{
		calc_insert_cost(state, costs[i], state->b.stack[i]);
		i--;
	}
}

static int	get_best_cost_i(t_cost_to_insert **costs, int b_top)
{
	int best;
	int	i;

	best = b_top;
	i = b_top;
	while (i > -1)
	{
		if (costs[i]->total_cost < costs[best]->total_cost)
			best = i;
		i--;
	}
	return (best);
}

static	void	execute_cost(t_p_swap *state, t_cost_to_insert *cost)
{
	while (cost->ra-- > 0)
		ra(state);
	while (cost->rb-- > 0)
		rb(state);
	while (cost->rra-- > 0)
		rra(state);
	while (cost->rrb-- > 0)
		rrb(state);
	while (cost->rr-- > 0)
		rr(state);
	while (cost->rrr-- > 0)
		rrr(state);
	while (cost->pa-- > 0)
		pa(state);
	while (cost->pb-- > 0)
		pb(state);
}

static void	execute_best_cost(t_p_swap *state, t_cost_to_insert **costs)
{
	int best;

	best = get_best_cost_i(costs, state->b.top);
	execute_cost(state, costs[best]); //executando sempre a primeira opcao
}

static void rotate_as_needed(t_p_swap *state)
{
	int z_index;
	int distance;

	z_index = get_index_of(state->a.stack, state->a.size, 0);
	distance = state->a.top - z_index;
	if (distance > z_index)
	{
		while (state->a.stack[state->a.top] != 0)
			rra(state);
	}
	else
	{
		while (state->a.stack[state->a.top] != 0)
			ra(state);
	}
}

static int	stack_has_value_above(t_stack *stk, t_stack *keeper, int value)
{
	int i;

	i = 0;
	while (i <= stk->top)
	{
		if (stk->stack[i] <= value)
		{
			if (get_index_of(keeper->stack, keeper->size, stk->stack[i]) == -1)
				return (1);
		}
		i++;
	}
	return (0);
}

void	push_allowed_to_b(t_p_swap *state)
{
	int i;
	int top_value;
	int keep_i;

	i = state->a.top;
	while (i > -1)
	{
		top_value = get_stack_top(&(state->a));
		keep_i = get_index_of(state->keeper.stack, state->keeper.top + 1, top_value);
		if (keep_i == -1)
			pb(state);
		else
			ra(state);
		i--;
	}
}

void	push_allowed_sectors_to_b(t_p_swap *state)
{
	int	top_value;
	int	section;
	int	keep_i;
	int	increment;

	section = state->a.size * 0.50;
	increment = state->a.size * 0.1;
	if (increment == 0)
		increment = 1;
	while (state->a.top > state->keeper.top)
	{
		while (stack_has_value_above(&(state->a), &(state->keeper), section))
		{
			top_value = get_stack_top(&(state->a));
			if (top_value <= section)
			{
				keep_i = get_index_of(state->keeper.stack, state->keeper.top + 1, top_value);
				if (keep_i == -1)
					pb(state);
				else
					ra(state);
			}
			else
				ra(state);
		}
		section += increment;
	}
}

void	quick_selection(t_p_swap *state)
{
	int	top_value;
	int	section;
	t_cost_to_insert **costs;

	build_keep_stack(state);
	
	
	//while (state->a.top > -1)
	//	pb(state);
	push_allowed_sectors_to_b(state);	
	//push_allowed_to_b(state);
	
	costs = start_cost_array(state->max_value + 1);
	while (state->b.top > -1)
	{
		build_cost_array(state, costs);
		execute_best_cost(state, costs);
		clean_cost_array(costs, state->max_value);
	}
	rotate_as_needed(state);
	destroy_cost_array(costs, state->max_value + 1);
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
		//quick_selection(&state);
	}
	optmize_op_list(state.operations);
	print_op_list(state.operations);
	destroy_state(&state);
	return (0);
}
