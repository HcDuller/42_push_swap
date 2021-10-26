/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:25:05 by hcduller          #+#    #+#             */
/*   Updated: 2021/06/08 21:49:36 by hcduller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*allocator(t_list *src, void *(*f)(void *));
static	void		clean_all(t_list *fl, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*r[4];

	if (!lst)
		return (NULL);
	r[0] = lst;
	r[1] = NULL;
	r[2] = NULL;
	r[3] = NULL;
	while (r[0])
	{
		r[2] = allocator(r[0], f);
		if (!r[2])
		{
			clean_all(r[0], del);
			return (NULL);
		}
		if (r[1])
			r[1]->next = r[2];
		else
			r[3] = r[2];
		r[1] = r[2];
		r[0] = r[0]->next;
	}
	return (r[3]);
}

t_list	*allocator(t_list *src, void *(*f)(void *))
{
	t_list	*p;

	p = NULL;
	if (f)
		p = ft_lstnew(f(src->content));
	return (p);
}

void	clean_all(t_list *fl, void (*del)(void *))
{
	if (fl->next)
		clean_all(fl->next, del);
	del(fl);
	fl = NULL;
	free(fl);
}
