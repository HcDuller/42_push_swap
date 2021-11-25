/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_op_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:54:45 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/11 18:46:19 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_op_list	*get_first_op_item(t_op_list *any_op_item)
{
	t_op_list	*first_item;

	if (any_op_item != NULL)
	{
		first_item = any_op_item;
		while (first_item->previous)
			first_item = first_item->previous;
		return (first_item);
	}
	return (NULL);
}
