/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_op_item.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:54:48 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/25 15:14:04 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_op_list	*get_last_op_item(t_op_list *any_op_item)
{
	t_op_list	*last_item;

	if (any_op_item != NULL)
	{
		last_item = any_op_item;
		while (last_item->next)
			last_item = last_item->next;
		return (last_item);
	}
	return (NULL);
}
