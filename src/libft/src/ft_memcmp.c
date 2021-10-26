/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:16:30 by hcduller          #+#    #+#             */
/*   Updated: 2021/05/28 15:29:11 by hcduller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*a1;
	char	*a2;
	size_t	i;

	i = 0;
	a1 = (char *)s1;
	a2 = (char *)s2;
	while (i < n)
	{
		if ((unsigned char)a1[i] != (unsigned char)a2[i])
			return ((unsigned char)a1[i] - (unsigned char)a2[i]);
		i++;
	}
	return (0);
}
