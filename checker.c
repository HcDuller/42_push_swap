/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:51:52 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/07 15:46:28 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <get_next_line.h>

void	manual_checker(t_p_swap *state)
{
	//char	buf[4];
	char	**buf;
	int		l;

	buf = ft_calloc(1, sizeof(char *));
	while (1)
	{
		get_next_line(1, buf);
		l = ft_strlen(*buf);
		if (l > 1)
		{
			if ((*buf)[0] == 's')
			{
				if ((*buf)[1] == 'a')
					sa(state);
				else if ((*buf)[1] == 'b')
					sb(state);
				else if ((*buf)[1] == 's')
					ss(state);
			}
			else if ((*buf)[0] == 'p')
			{
				if ((*buf)[1] == 'a')
					pa(state);
				else if ((*buf)[1] == 'b')
					pb(state);
			}
			else if ((*buf)[0] == 'r')
			{
				if (l < 3)
				{
					if ((*buf)[1] == 'a')
						ra(state);
					else if ((*buf)[1] == 'b')
						rb(state);
					else if ((*buf)[1] == 'r')
						rr(state);
				}
				else if ((*buf)[1] == 'r')
				{
					if ((*buf)[2] == 'a')
						rra(state);
					else if ((*buf)[2] == 'b')
						rrb(state);
					else if ((*buf)[2] == 'r')
						rrr(state);
				}
			}
			free(*buf);
			*buf = NULL;
		}
		print_state(*state);
		//ft_putstr_fd("[a]:\t", 1);
		//print_stack(state->a);
		//ft_putstr_fd("[b]:\t", 1);
		//print_stack(state->b);
	}
}

int	main(int argc, char *argv[])
{
	t_p_swap	state;

	if (argc > 1)
	{
		state = new_state_from_input(argc, argv);
		print_stack(state.a);
		manual_checker(&state);
		destroy_state(&state);
	}
	return (0);
}
