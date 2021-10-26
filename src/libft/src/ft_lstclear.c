/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:39:39 by hcduller          #+#    #+#             */
/*   Updated: 2021/06/07 19:35:16 by hcduller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	*a;

	if (!lst || !del)
		return ;
	p = *lst;
	while (p)
	{
		a = p->next;
		del(p->content);
		free(p);
		p = a;
	}
	*lst = NULL;
}
