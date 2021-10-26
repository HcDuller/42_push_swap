/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:28:14 by hde-camp          #+#    #+#             */
/*   Updated: 2021/06/07 23:08:15 by hcduller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*r;

	r = (char *)s;
	while (*r)
	{
		if (*r == (char)c)
			return (r);
		r++;
		if (*r == (char)c)
			return (r);
		if (!*r)
			return (0);
	}
	if (!*r && (char)c == 0)
		return (r);
	return (0);
}
