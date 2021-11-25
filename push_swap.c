/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:57:01 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/25 13:08:16 by hde-camp         ###   ########.fr       */
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

void	quick_merge_sort(t_p_swap *state)
{
	int	i;
	int	top_value;
	int	keep_i;

	build_keep_stack(state);
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
		//quick_heap_sort(&state);
		quick_merge_sort(&state);
	}
	optmize_op_list(state.operations);
	print_op_list(state.operations);
	//print_state(state);
	destroy_state(&state);
	return (0);
}
