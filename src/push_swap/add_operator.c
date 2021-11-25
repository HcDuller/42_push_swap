/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:56:05 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/23 15:56:11 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_op_list	*add_operator(t_op_list *last_op, t_operator op)
{
	t_op_list	*new;

	new = new_operator(op);
	if (new)
	{
		if (last_op)
		{
			last_op->next = new;
			new->previous = last_op;
		}
	}
	return (new);
}
