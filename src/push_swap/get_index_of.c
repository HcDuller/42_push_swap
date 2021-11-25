/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_of.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:28:51 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/25 18:58:47 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_index_of(int *array, int array_size, int value)
{
	int	i;

	i = 0;
	while (i < array_size)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
