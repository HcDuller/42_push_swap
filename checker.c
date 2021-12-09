/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:51:52 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/09 14:09:15 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <get_next_line.h>

void static	rel(t_p_swap *state, char *buf, int *is_ok)
{
	int		l;

	get_next_line(1, &buf);
	l = ft_strlen(buf);
	if (l > 1)
	{
		if (buf[0] == 's')
			s_handler(state, buf, is_ok);
		else if (buf[0] == 'p')
			p_handler(state, buf, is_ok);
		else if (buf[0] == 'r')
			r_handler(state, buf, is_ok);
	}
	else
		*is_ok = 0;
	free(buf);
	buf = NULL;
}

void static	manual_checker(t_p_swap *state)
{
	char	*buf;
	int		is_ok;

	is_ok = 1;
	buf = NULL;
	while (is_ok)
	{
		rel(state, buf, &is_ok);
	}
	if (state->b.top > -1)
		ft_putstr_fd("KO\n", 1);
	else if (stack_is_sorted(state->a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
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
