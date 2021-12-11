/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:54:40 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/10 15:48:50 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	s_handler(t_p_swap *state, char *str, int *is_ok)
{
	if (ft_strlen(str) == 2)
	{
		if (str[1] == 'a')
			sa(state);
		else if (str[1] == 'b')
			sb(state);
		else if (str[1] == 's')
			ss(state);
	}
	else
		*is_ok = 2;
}

void	p_handler(t_p_swap *state, char *str, int *is_ok)
{
	if (ft_strlen(str) == 2)
	{
		if (str[1] == 'a')
			pa(state);
		else if (str[1] == 'b')
			pb(state);
	}
	else
		*is_ok = 2;
}

void	rr_handler(t_p_swap *state, char *str, int *is_ok)
{
	if (str[2] == 'a')
		rra(state);
	else if (str[2] == 'b')
		rrb(state);
	else if (str[2] == 'r')
		rrr(state);
	else
		*is_ok = 2;
}

void	r_handler(t_p_swap *state, char *str, int *is_ok)
{
	int	l;

	l = ft_strlen(str);
	if (l == 2)
	{
		if (str[1] == 'a')
			ra(state);
		else if (str[1] == 'b')
			rb(state);
		else if (str[1] == 'r')
			rr(state);
		else
			*is_ok = 2;
	}
	else if (l == 3 && str[1] == 'r')
		rr_handler(state, str, is_ok);
	else
		*is_ok = 2;
}
