/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:25:30 by hcduller          #+#    #+#             */
/*   Updated: 2021/06/07 15:21:06 by hcduller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		r;

	if (!lst)
		return (0);
	r = 0;
	p = lst;
	while (p)
	{
		r++;
		if (!p->content)
			return (r);
		p = p->next;
	}
	return (r);
}
