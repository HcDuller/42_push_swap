/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:37:30 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/09 16:01:48 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_a_duplicate(t_p_swap *state, int value)
{
	int	i;

	i = state->a.top;
	while (i > -1)
	{
		if (state->a.stack[i] == value)
			return (1);
		i--;
	}
	return (0);
}

void static	push_arg_into_state(t_p_swap *state, int value, int *is_ok)
{
	if (is_a_duplicate(state, value))
	{
		*is_ok = 0;
		return ;
	}
	push_to_stack(&state->a, value);
	push_to_stack(&state->keeper, value);
}

void static	list_to_args(t_p_swap *state, int *is_ok)
{
	int		temp_val;
	t_list	*aux;

	while (state->input)
	{
		temp_val = strict_atoi(state->input->content, is_ok);
		push_arg_into_state(state, temp_val, is_ok);
		if (!*is_ok)
		{
			exit_error(state);
		}
		aux = state->input->next;
		free(state->input);
		state->input = aux;
	}
}

void	read_input(t_p_swap *state, int argc, char *argv[])
{
	int		is_ok;
	int		arg;

	arg = 1;
	while (arg < argc)
	{
		state->input = sliced_arg(state, argv[arg]);
		arg++;
	}
	start_state(state, ft_lstsize(state->input));
	list_to_args(state, &is_ok);
}
