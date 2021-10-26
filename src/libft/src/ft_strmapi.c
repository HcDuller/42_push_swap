/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:51:28 by hcduller          #+#    #+#             */
/*   Updated: 2021/06/01 21:55:30 by hcduller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	p = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	i = 0;
	if (p)
	{
		while (s[i])
		{
			p[i] = f(i, s[i]);
			i++;
		}
	}
	return (p);
}
