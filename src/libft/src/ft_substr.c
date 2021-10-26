/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:23:18 by hcduller          #+#    #+#             */
/*   Updated: 2021/06/08 16:07:38 by hcduller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static	size_t	smaller(size_t a, size_t b);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	nl;
	size_t	sl;
	char	*ptr;

	if (!s)
		return (NULL);
	i = 0;
	sl = ft_strlen(s);
	if (sl < start)
		return (ft_calloc(1, 1));
	sl = ft_strlen(&s[start]);
	nl = smaller(sl, len);
	ptr = ft_calloc(nl + 1, sizeof(char));
	if (ptr)
	{		
		while (i < len && s[start + i])
		{
			*(ptr + i) = s[start + i];
			i++;
		}
	}
	return (ptr);
}

size_t	smaller(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}
