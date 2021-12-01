/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_state_from_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:27:43 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/30 14:15:35 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_array(int *array, int size)
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

void	replace_stack_values(t_p_swap *state)
{
	int		i;
	int		correct_place;
	int		*ordered;
	t_stack	*stk;

	i = 0;
	stk = &(state->a);
	ordered = state->ordered_stack;
	while (i <= state->a.top)
	{
		correct_place = get_index_of(ordered, stk->size, stk->stack[i]);
		stk->stack[i] = correct_place;
		state->keeper.stack[i] = correct_place;
		i++;
	}
}

int	*array_from_stack(t_stack a)
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
	sort_array(input_array, a.size);
	return (input_array);
}

t_p_swap	new_state_from_input(int argc, char *argv[])
{
	t_p_swap	state;
	int			is_ok;

	if (argc == 1)
	{
		ft_putstr_fd("At least one argument must be provided.\n", 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		argc--;
		state.a = new_stack(argc);
		state.b = new_stack(argc);
		state.q_s_groups = new_stack(argc);
		state.keeper = new_stack(argc);
		state.map = ft_calloc(state.a.size / 2 + 1, sizeof(t_tuple));
		state.operations = NULL;
		state.keeper_cap = -1;
		state.moves = 0;
		state.max_value = argc - 1;
		while (argc >= 1)
		{
			push_to_stack(&state.a, strict_atoi(argv[argc], &is_ok));
			push_to_stack(&state.keeper, strict_atoi(argv[argc], &is_ok));
			if (!is_ok)
			{
				destroy_state(&state);
				ft_putstr_fd("Error: The argument[", 2);
				ft_putchar_fd(*argv[argc], 2);
				ft_putstr_fd("] is invalid.\n", 2);
				exit(EXIT_FAILURE);
			}
			argc--;
		}
	}
	if (argc == 0)
	{
		state.ordered_stack = ordered_array_from_stack(state.a);
		replace_stack_values(&state);
	}
	return (state);
}
