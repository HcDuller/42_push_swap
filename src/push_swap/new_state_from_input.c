/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_state_from_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:27:43 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/08 20:42:00 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
	return (state->input);
}

void	exit_error(t_p_swap *state)
{
	destroy_lst(&state->input);
	destroy_state(state);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
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
		read_input(&state, &argc, argv);
	}
	if (argc == 0)
	{
		state.ordered_stack = ordered_array_from_stack(state.a);
		replace_stack_values(&state);
	}
	return (state);
}
