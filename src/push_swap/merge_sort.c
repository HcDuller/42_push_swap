/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:52:04 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/23 15:52:10 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	merge_sort(t_p_swap *state)
{
	build_base_merge_list(state);
	while (!stack_is_sorted(state->a) || state->b.top > -1)
	{
		do_a_merge(state);
		mutate_merge_sequence(&state->map);
	}
}
