/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutate_merge_sequence.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:51:19 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/23 15:51:26 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	mutate_merge_sequence(t_tuple **input)
{
	int		total_elements;
	int		i_index;
	int		n_index;
	int		direction;
	t_tuple	*new_tuple;

	total_elements = 0;
	i_index = 0;
	direction = (*input)[0].direction * -1;
	while ((*input)[i_index].a != 0)
	{
		total_elements += (*input)[i_index].a;
		total_elements += (*input)[i_index].b;
		i_index++;
	}
	new_tuple = ft_calloc(i_index / 2 + i_index % 2  + 1, sizeof(t_tuple));
	i_index--;
	n_index = 0;
	while (total_elements > 0)
	{
		new_tuple[n_index].direction = direction;
		if (i_index < 1)
		{
			new_tuple[n_index].a = (*input)[i_index].a + (*input)[i_index].b;
			new_tuple[n_index].b = 0;
			total_elements -= (new_tuple[n_index].a + new_tuple[n_index].b);
			i_index -= 1;
		}
		else
		{
			new_tuple[n_index].a = (*input)[i_index].a + (*input)[i_index].b;
			new_tuple[n_index].b = (*input)[i_index - 1].a + (*input)[i_index - 1].b;
			total_elements -= (new_tuple[n_index].a + new_tuple[n_index].b);
			i_index -= 2;
		}
		n_index++;
	}
	free(*input);
	*input = new_tuple;
}
