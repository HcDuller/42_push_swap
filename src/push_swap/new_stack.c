/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:24:30 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/05 18:04:33 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	new_stack(int size)
{
	t_stack	stack;

	if (size < 1)
		stack.size = 1;
	else
		stack.size = size;
	stack.stack = NULL;
	stack.stack = ft_calloc(stack.size, sizeof(int *));
	stack.top = -1;
	return (stack);
}
