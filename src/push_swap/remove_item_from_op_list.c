/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_item_from_op_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:05:24 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/11 18:12:01 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_op_list	*remove_item_from_op_list(t_op_list	*any_operator)
{
	t_op_list	*previous;
	t_op_list	*next;

	if (any_operator != NULL)
	{
		previous = any_operator->previous;
		next = any_operator->next;
		previous->next = next;
		next->previous = previous;
		free(any_operator);
		if (next)
			return(next);
		return (previous);
	}
	return (NULL);
}
