/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_sized_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:47:51 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/23 15:47:59 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_three_sized_stack(t_p_swap *state)
{
	pb(state);
	if (state->a.stack[1] > state->a.stack[0])
		sa(state);
	pa(state);
	if (state->a.stack[2] > state->a.stack[0])
		ra(state);
	else if (state->a.stack[2] > state->b.stack[1])
		sa(state);
}
