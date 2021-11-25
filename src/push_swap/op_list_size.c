/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:54:41 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/11 19:17:22 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	op_list_size(t_op_list *any_op_item)
{
	t_op_list	*aux;
	int			size;

	size = 0;
	aux = get_first_op_item(any_op_item);
	while (aux->next)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}
