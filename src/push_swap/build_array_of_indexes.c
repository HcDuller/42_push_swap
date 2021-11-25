/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_array_of_indexes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:13:14 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/25 17:13:44 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	*build_array_of_indexes(t_stack *src)
{
	int	*indexes;
	int	i;

	indexes = ft_calloc(src->size, sizeof(int));
	i = 0;
	while (i < src->size)
	{
		indexes[i] = get_index_of(src->stack, src->size, i);
		i++;
	}
	return (indexes);
}
