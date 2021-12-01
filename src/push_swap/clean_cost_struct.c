/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_cost_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:14:37 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/30 16:15:35 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	clean_cost_struct(t_cost_to_insert *cost)
{
	cost->pa = 0;
	cost->pb = 0;
	cost->ra = 0;
	cost->rb = 0;
	cost->rra = 0;
	cost->rrb = 0;
	cost->rr = 0;
	cost->rrr = 0;
	cost->sa = 0;
	cost->sb = 0;
	cost->ss = 0;
	cost->total_cost = 0;
}
