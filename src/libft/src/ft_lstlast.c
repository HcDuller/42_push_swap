/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:45:16 by hcduller          #+#    #+#             */
/*   Updated: 2021/06/04 16:06:47 by hcduller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{	
	t_list	*p;

	if (!lst)
		return (0);
	p = lst;
	while (p->next)
	{
		p = p->next;
	}
	return (p);
}
