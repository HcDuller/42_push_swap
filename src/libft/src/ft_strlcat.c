/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:27:13 by hde-camp          #+#    #+#             */
/*   Updated: 2021/06/08 12:11:21 by hcduller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	sc;
	size_t	sd;
	size_t	i;

	sc = ft_strlen(src);
	sd = ft_strlen(dst);
	i = 0;
	if (size > sd)
		sc = sc + sd;
	else
		sc = sc + size;
	while (src[i] && sd + 1 < size)
	{
		dst[sd++] = src[i++];
		if (!(src[i] && sd + 1 < size))
			dst[sd] = '\0';
	}
	return (sc);
}
