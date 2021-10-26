/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:57:39 by hde-camp          #+#    #+#             */
/*   Updated: 2021/06/08 11:23:35 by hcduller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static	size_t	smaller(size_t a, size_t b);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	r;
	size_t	l;

	if (!src || !dst)
		return (0);
	r = ft_strlen(src);
	if (dstsize)
	{
		l = smaller(r, dstsize - 1);
		i = 0;
		while (i < l)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (r);
}

static	size_t	smaller(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}
