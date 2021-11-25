/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:06:27 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/25 14:07:14 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	copy_stack_a_to_b(t_stack *a, t_stack *b)
{
	int	i;

	while (b->top > -1)
		pop_from_stack(b);
	i = 0;
	while (i <= a->top)
		push_to_stack(b, a->stack[i++]);
}
