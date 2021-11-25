/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_op_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:54:38 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/25 17:45:25 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	destroy_op_list(t_op_list **any_op_item)
{
	t_op_list	*aux_item;
	t_op_list	*swapper;

	aux_item = get_first_op_item(*any_op_item);
	while (aux_item->next)
	{
		swapper = aux_item->next;
		free(aux_item);
		aux_item = swapper;
	}
	if (aux_item)
		free(aux_item);
}
