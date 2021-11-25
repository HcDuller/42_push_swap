/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutate_merge_sequence.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:51:19 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/25 18:57:37 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	mutate_merge_sequence(t_tuple **input)
{
	int		total_elements;
	int		i_i;
	int		n_i;
	int		direction;
	t_tuple	*n_tpl;

	total_elements = 0;
	i_i = 0;
	direction = (*input)[0].direction * -1;
	while ((*input)[i_i].a != 0)
	{
		total_elements += (*input)[i_i].a;
		total_elements += (*input)[i_i].b;
		i_i++;
	}
	n_tpl = ft_calloc(i_i / 2 + i_i % 2 + 1, sizeof(t_tuple));
	i_i--;
	n_i = 0;
	while (total_elements > 0)
	{
		n_tpl[n_i].direction = direction;
		if (i_i < 1)
		{
			n_tpl[n_i].a = (*input)[i_i].a + (*input)[i_i].b;
			n_tpl[n_i].b = 0;
			total_elements -= (n_tpl[n_i].a + n_tpl[n_i].b);
			i_i -= 1;
		}
		else
		{
			n_tpl[n_i].a = (*input)[i_i].a + (*input)[i_i].b;
			n_tpl[n_i].b = (*input)[i_i - 1].a + (*input)[i_i - 1].b;
			total_elements -= (n_tpl[n_i].a + n_tpl[n_i].b);
			i_i -= 2;
		}
		n_i++;
	}
	free(*input);
	*input = n_tpl;
}
