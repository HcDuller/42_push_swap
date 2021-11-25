/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:56:55 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/25 17:46:18 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_op_list	*first_item(t_op_list	*any_op_item)
{
	t_op_list	*first;

	first = any_op_item;
	while (first->previous != NULL)
		first = first->previous;
	return (first);
}

void	print_op_list(t_op_list	*any_op_item)
{
	char		*printable[11];
	t_op_list	*op;

	printable[0] = "pa\n";
	printable[1] = "pb\n";
	printable[2] = "sa\n";
	printable[3] = "sb\n";
	printable[4] = "ss\n";
	printable[5] = "ra\n";
	printable[6] = "rb\n";
	printable[7] = "rr\n";
	printable[8] = "rra\n";
	printable[9] = "rrb\n";
	printable[10] = "rrr\n";
	if (any_op_item != NULL)
	{
		op = first_item(any_op_item);
		while (op->next != NULL)
		{
			ft_putstr_fd(printable[op->operator], 1);
			op = op->next;
		}
		if (op != NULL)
			ft_putstr_fd(printable[op->operator], 1);
	}
}
