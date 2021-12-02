/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutate_merge_sequence.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:51:19 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 15:42:29 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	start_values(t_tuple **input, t_tuple **n_tpl, \
int *i_i, int *total_elements)
{
	*total_elements = 0;
	*i_i = 0;
	while ((*input)[*i_i].a != 0)
	{
		*total_elements += (*input)[*i_i].a;
		*total_elements += (*input)[*i_i].b;
		*i_i += 1;
	}
	*n_tpl = ft_calloc(*i_i / 2 + *i_i % 2 + 1, sizeof(t_tuple));
	*i_i -= 1;
}

static void	handle_last_tuple(t_tuple *new, t_tuple *input, int *i_i, int *n_i)
{
	new[*n_i].a = input[*i_i].a + input[*i_i].b;
	new[*n_i].b = 0;
	i_i -= 1;
}

void	mutate_merge_sequence(t_tuple **input)
{
	int		total_elements;
	int		i_i;
	int		n_i;
	int		direction;
	t_tuple	*n_tpl;

	direction = (*input)[0].direction * -1;
	start_values(input, &n_tpl, &i_i, &total_elements);
	n_i = 0;
	while (total_elements > 0)
	{
		n_tpl[n_i].direction = direction;
		if (i_i < 1)
			handle_last_tuple(n_tpl, (*input), &i_i, &n_i);
		else
		{
			n_tpl[n_i].a = (*input)[i_i].a + (*input)[i_i].b;
			n_tpl[n_i].b = (*input)[i_i - 1].a + (*input)[i_i - 1].b;
			i_i -= 2;
		}
		total_elements -= (n_tpl[n_i].a + n_tpl[n_i].b);
		n_i++;
	}
	free(*input);
	*input = n_tpl;
}
