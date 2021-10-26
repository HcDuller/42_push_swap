/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:23:40 by hcduller          #+#    #+#             */
/*   Updated: 2021/06/07 22:55:46 by hcduller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*s;
	char			*d;
	unsigned int	i;

	i = 0;
	s = (char *)src;
	d = dst;
	while (i < n)
	{
		d[i] = s[i];
		if ((unsigned char)s[i++] == (unsigned char)c)
			return (d + i);
	}
	return (0);
}
