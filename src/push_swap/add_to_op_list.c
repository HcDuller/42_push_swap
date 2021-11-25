/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_op_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:54:32 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/11 18:01:11 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_op_list	*add_to_op_list(t_op_list *last_operator, t_operator new_operator)
{
	t_op_list	*new;

	new = create_op_item(new_operator);
	if (last_operator != NULL)
	{
		new->previous = last_operator;
		last_operator->next = new;
	}
	return (new);
}
