/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:54:53 by hcduller          #+#    #+#             */
/*   Updated: 2021/06/03 17:14:08 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*aux;

	if (!s1 || !s2)
		return (NULL);
	ptr = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (ptr)
	{
		aux = ptr;
		while (*s1)
			*aux++ = *s1++;
		while (*s2)
			*aux++ = *s2++;
		*aux = 0;
		return (ptr);
	}
	return (NULL);
}
