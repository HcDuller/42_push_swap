/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:55:31 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/23 15:55:37 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_op_list	*new_operator(t_operator op)
{
	t_op_list	*new;

	new = NULL;
	new = ft_calloc(1, sizeof(t_op_list));
	if (new != NULL)
	{
		new->operator = op;
		new->next = NULL;
		new->previous = NULL;
	}
	return (new);
}
