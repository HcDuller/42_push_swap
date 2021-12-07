/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_state_from_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:27:43 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/07 18:13:13 by hde-camp         ###   ########.fr       */
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

void	*sliced_arg(t_p_swap *state, char *str)
{
	int		i;
	int		l;

	i = 0;
	l = ft_strlen(str);
	while (i < l)
	{
		while (is_space(str[i]))
			str[i++] = 0;
		if (str[i])
		{
			if (state->input == NULL)
				state->input = ft_lstnew(&str[i]);
			else
				ft_lstadd_back(&state->input, ft_lstnew(&str[i]));
			while (i < l)
			{
				if (!is_space(str[i]))
					i++;
				else
					break ;
			}
		}
	}
	return state->input;
}

static void	exit_error(t_p_swap *state)
{
	destroy_state(state);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	destroy_lst(t_list **lst)
{
	t_list *aux;

	while (*lst)
	{
		aux = (*lst)->next;
		free(*lst);
		*lst = aux;
	}
}

void	list_to_args(t_p_swap *state, t_list *lst, int *is_ok)
{
	int		temp_val;
	t_list	*aux;


	while (lst)
	{
		temp_val = strict_atoi(lst->content, is_ok);
		if (!is_ok)
		{
			destroy_lst(&lst);
			exit_error(state);
		}
		aux = lst->next;
		free(lst);
		lst = aux;
		push_to_stack(&state->a, temp_val);
		push_to_stack(&state->keeper, temp_val);
	}
}

void static	read_input(t_p_swap *state, int *argc, char *argv[])
{
	int		is_ok;
	//int		input_v;
	t_list	*input_list;

	while (*argc >= 1)
	{
		input_list = sliced_arg(state, argv[*argc]);
		//input_v = strict_atoi(argv[*argc], &is_ok);
		//if (!is_ok)
		//{
		//	destroy_state(state);
		//	ft_putstr_fd("Error\n", 2);
		//	exit(EXIT_FAILURE);
		//}
		//push_to_stack(&state->a, input_v);
		//push_to_stack(&state->keeper, input_v);
		*argc -= 1;
	}
	start_state(state, ft_lstsize(state->input));
	list_to_args(state, input_list, &is_ok);
}

t_p_swap	new_state_from_input(int argc, char *argv[])
{
	t_p_swap	state;

	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		argc--;
		state.input = NULL;
//		start_state(&state, argc);
		read_input(&state, &argc, argv);
	}
	if (argc == 0)
	{
		state.ordered_stack = ordered_array_from_stack(state.a);
		replace_stack_values(&state);
	}
	return (state);
}
