/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_state_from_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:27:43 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 21:08:40 by hde-camp         ###   ########.fr       */
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

static int	*ordered_array_from_stack(t_stack	a)
{
	int	*input_array;

	input_array = array_from_stack(a);
	heap_sort_array(input_array, a.size);
	return (input_array);
}

void static	start_state(t_p_swap *state, int size)
{
	state->a = new_stack(size);
	state->b = new_stack(size);
	state->q_s_groups = new_stack(size);
	state->keeper = new_stack(size);
	state->map = ft_calloc(state->a.size / 2 + 1, sizeof(t_tuple));
	state->operations = NULL;
	state->keeper_cap = -1;
	state->moves = 0;
	state->max_value = size - 1;
}

void static	read_input(t_p_swap *state, int *argc, char *argv[])
{
	int			is_ok;

	while (*argc >= 1)
	{
		push_to_stack(&state->a, strict_atoi(argv[*argc], &is_ok));
		push_to_stack(&state->keeper, strict_atoi(argv[*argc], &is_ok));
		if (!is_ok)
		{
			destroy_state(state);
			ft_putstr_fd("Error: The argument[", 2);
			ft_putchar_fd(*argv[*argc], 2);
			ft_putstr_fd("] is invalid.\n", 2);
			exit(EXIT_FAILURE);
		}
		*argc -= 1;
	}
}

t_p_swap	new_state_from_input(int argc, char *argv[])
{
	t_p_swap	state;

	if (argc == 1)
	{
		ft_putstr_fd("At least one argument must be provided.\n", 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		argc--;
		start_state(&state, argc);
		read_input(&state, &argc, argv);
	}
	if (argc == 0)
	{
		state.ordered_stack = ordered_array_from_stack(state.a);
		replace_stack_values(&state);
	}
	return (state);
}
