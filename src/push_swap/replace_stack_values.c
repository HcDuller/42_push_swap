/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_stack_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:58:11 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 20:59:36 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	replace_stack_values(t_p_swap *state)
{
	int		i;
	int		correct_place;
	int		*ordered;
	t_stack	*stk;

	i = 0;
	stk = &(state->a);
	ordered = state->ordered_stack;
	while (i <= state->a.top)
	{
		correct_place = get_index_of(ordered, stk->size, stk->stack[i]);
		stk->stack[i] = correct_place;
		state->keeper.stack[i] = correct_place;
		i++;
	}
}
