/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:20:54 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/02 21:21:09 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	copy_cost(t_cost_to_insert *src, t_cost_to_insert *dest)
{
	dest->pa = src->pa;
	dest->pb = src->pb;
	dest->ra = src->ra;
	dest->rb = src->rb;
	dest->rra = src->rra;
	dest->rrb = src->rrb;
	dest->rr = src->rr;
	dest->rrr = src->rrr;
	dest->sa = src->sa;
	dest->sb = src->sb;
	dest->ss = src->ss;
	dest->total_cost = src->total_cost;
}
