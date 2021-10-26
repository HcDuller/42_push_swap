/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:50:08 by hcduller          #+#    #+#             */
/*   Updated: 2021/06/02 17:26:15 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (dst > src)
	{
		i = len;
		while (i >= 1)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dst);
}
