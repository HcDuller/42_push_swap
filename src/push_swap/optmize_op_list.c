/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optmize_op_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:39:35 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/23 15:43:24 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	optmize_op_list(t_op_list *any_op)
{

	if (any_op)
	{
		while (any_op->previous != NULL)
		{
			any_op = any_op->previous;
		}
		while (any_op->next != NULL)
		{
			if ((any_op->operator == RA && any_op->next->operator == RRA) || \
			(any_op->operator == RRA && any_op->next->operator == RA) || \
			(any_op->operator == RB && any_op->next->operator == RRB) || \
			(any_op->operator == RRB && any_op->next->operator == RB) \
			)
			{
				any_op = remove_item_from_op_list(any_op);
				any_op = remove_item_from_op_list(any_op);
				any_op = any_op->previous;
			}
			else
				any_op = any_op->next;
		}
	}
}
