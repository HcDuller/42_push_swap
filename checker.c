/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:51:52 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/16 12:38:07 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	manual_checker(t_p_swap *state)
{
	char	buf[4];
	int		l;

	while (1)
	{
		ft_bzero(&buf, 4);
		read(0, &buf, 4);
		buf[3] = 0;
		replace_nl(&buf[0]);
		l = ft_strlen(buf);
		if (l > 1)
		{
			if (buf[0] == 's')
			{
				if (buf[1] == 'a')
					sa(state);
				else if (buf[1] == 'b')
					sb(state);
				else if (buf[1] == 's')
					ss(state);
			}
			else if (buf[0] == 'p')
			{
				if (buf[1] == 'a')
					pa(state);
				else if (buf[1] == 'b')
					pb(state);
			}
			else if (buf[0] == 'r')
			{
				if (l < 3)
				{
					if (buf[1] == 'a')
						ra(state);
					else if (buf[1] == 'b')
						rb(state);
					else if (buf[1] == 'r')
						rr(state);
				}
				else if (buf[1] == 'r')
				{
					if (buf[2] == 'a')
						rra(state);
					else if (buf[2] == 'b')
						rrb(state);
					else if (buf[2] == 'r')
						rrr(state);
				}
			}
		}
		ft_putstr_fd("[a]:\t", 1);
		print_stack(state->a);
		ft_putstr_fd("[b]:\t", 1);
		print_stack(state->b);
	}
}

int	main(int argc, char *argv[])
{
	int			argc_i;
	int			is_ok;
	int			buf;
	t_p_swap	state;

	state = new_state_from_input(argc, argv);
	print_stack(state.a);
	manual_checker(&state);
	destroy_stack(&state.a);
	destroy_stack(&state.b);
	return (0);
}
