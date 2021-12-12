/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:51:52 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/12 14:10:28 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <get_next_line.h>

void static	command_handler(t_p_swap *state, char *buf, int *is_ok)
{
	int	l;

	l = ft_strlen(buf);
	if (l > 1 && l < 4)
	{
		if (buf[0] == 's')
			s_handler(state, buf, is_ok);
		else if (buf[0] == 'p')
			p_handler(state, buf, is_ok);
		else if (buf[0] == 'r')
			r_handler(state, buf, is_ok);
		else
			*is_ok = 2;
	}
	else if (l == 0)
		*is_ok = 0;
	else
		*is_ok = 2;
}

void static	rel(t_p_swap *state, char *buf, int *is_ok)
{
	int	i_size;

	i_size = get_next_line(0, &buf);
	if (buf && i_size > 0)
	{
		command_handler(state, buf, is_ok);
		free(buf);
	}
	else
	{
		*is_ok = 0;
	}
	buf = NULL;
}

void static	manual_checker(t_p_swap *state)
{
	char	*buf;
	int		is_ok;

	is_ok = 1;
	buf = NULL;
	while (is_ok == 1)
	{
		rel(state, buf, &is_ok);
	}
	if (is_ok == 0)
	{
		if (state->b.top > -1)
			ft_putstr_fd("KO\n", 1);
		else if (stack_is_sorted(state->a))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	else
		ft_putstr_fd("Error\n", 2);
}

int	main(int argc, char *argv[])
{
	t_p_swap	state;

	if (argc > 1)
	{
		state = new_state_from_input(argc, argv);
		manual_checker(&state);
		destroy_state(&state);
	}
	return (0);
}
