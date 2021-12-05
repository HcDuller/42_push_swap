/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optmize_op_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:39:35 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/05 02:02:03 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_op_list	*remove_vertical_redundancy(t_op_list *any_op)
{
	t_op_list	*output;

	if (any_op)
	{
		if (any_op->next)
		{
			if ((any_op->operator == RA && any_op->next->operator == RRA) || \
			(any_op->operator == RRA && any_op->next->operator == RA) || \
			(any_op->operator == RB && any_op->next->operator == RRB) || \
			(any_op->operator == RRB && any_op->next->operator == RB) \
			)
			{
				output = any_op->previous;
				any_op = remove_item_from_op_list(any_op);
				any_op = remove_item_from_op_list(any_op);
				if (output == NULL && any_op == NULL)
					return (NULL);
				if (output == NULL && any_op != NULL)
					return (any_op);
				return (remove_vertical_redundancy(output));
			}
		}
	}
	return (any_op);
}

t_op_list	*remove_horizontal_redundancy(t_op_list *any_op)
{
	t_op_list	*output;

	if (any_op)
	{
		if (any_op->next)
		{
			if ((any_op->operator == PA && any_op->next->operator == PB) || \
			(any_op->operator == PB && any_op->next->operator == PA))
			{
				output = any_op->previous;
				any_op = remove_item_from_op_list(any_op);
				any_op = remove_item_from_op_list(any_op);
				if (output == NULL && any_op == NULL)
					return (NULL);
				if (output == NULL && any_op != NULL)
					return (any_op);
				return (remove_horizontal_redundancy(output));
			}
		}
	}
	return (any_op);
}

void	optmize_op_list(t_op_list *any_op, t_op_list **destroy)
{
	if (any_op)
	{
		while (any_op->previous != NULL)
		{
			any_op = any_op->previous;
		}
		while (any_op->next != NULL)
		{
			any_op = remove_vertical_redundancy(any_op);
			any_op = remove_horizontal_redundancy(any_op);
			any_op = combine_vertical_moves(any_op);
			if (any_op)
			{
				if (any_op->next == NULL)
					break ;
				any_op = any_op->next;
			}
			else
			{
				*destroy = NULL;
				break ;
			}
		}
	}
}
