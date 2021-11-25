/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_op_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:54:23 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/11 17:58:44 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_op_list	*create_op_item(t_operator operator)
{
	t_op_list	*new_item;

	new_item = ft_calloc(1, sizeof(t_op_list));
	new_item->next = NULL;
	new_item->previous = NULL;
	new_item->operator = operator;
	return(new_item);
}
