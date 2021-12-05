/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_vertical_moves.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 01:56:28 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/05 02:05:37 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_op_list	*combine_into_rr(t_op_list *any_op)
{
	t_op_list	*output;
	t_op_list	*temp;

	if ((any_op->operator == RA && any_op->next->operator == RB) || \
	(any_op->operator == RB && any_op->next->operator == RA))
	{
		output = any_op->previous;
		any_op = remove_item_from_op_list(any_op);
		any_op = remove_item_from_op_list(any_op);
		temp = add_to_op_list(output, RR);
		temp->next = any_op;
		if (output == NULL && any_op == NULL)
			return (NULL);
		if (output == NULL && any_op != NULL)
			return (any_op);
		return (combine_vertical_moves(output));
	}
	return (any_op);
}

t_op_list	*combine_into_rrr(t_op_list *any_op)
{
	t_op_list	*output;
	t_op_list	*temp;

	if ((any_op->operator == RRA && any_op->next->operator == RRB) || \
	(any_op->operator == RRB && any_op->next->operator == RRA))
	{
		output = any_op->previous;
		any_op = remove_item_from_op_list(any_op);
		any_op = remove_item_from_op_list(any_op);
		temp = add_to_op_list(output, RRR);
		temp->next = any_op;
		if (output == NULL && any_op == NULL)
			return (NULL);
		if (output == NULL && any_op != NULL)
			return (any_op);
		return (combine_vertical_moves(output));
	}
	return (any_op);
}

t_op_list	*combine_vertical_moves(t_op_list *any_op)
{
	if (any_op)
	{
		if (any_op->next)
		{
			any_op = combine_into_rr(any_op);
			any_op = combine_into_rr(any_op);
		}
	}
	return (any_op);
}
