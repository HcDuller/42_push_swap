/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:32:06 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/08 20:38:22 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	destroy_lst(t_list **lst)
{
	t_list	*aux;

	while (*lst)
	{
		aux = (*lst)->next;
		free(*lst);
		*lst = aux;
	}
}
