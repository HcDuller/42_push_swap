/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:59:00 by hde-camp          #+#    #+#             */
/*   Updated: 2021/06/08 14:24:43 by hcduller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *haystack, const char *neddle, size_t len)
{
	size_t	i[4];

	if (!*neddle)
		return ((char *)haystack);
	if (!*haystack)
		return (NULL);
	i[0] = ft_strlen(haystack);
	i[1] = ft_strlen(neddle);
	if (i[0] < i[1])
		return (NULL);
	i[3] = i[0] - i[1];
	i[2] = 0;
	while (i[2] <= i[3] && i[2] + i[1] <= len)
	{
		if (!ft_strncmp(haystack + i[2], neddle, i[1]))
			return ((char *)(haystack + i[2]));
		i[2]++;
	}
	return (NULL);
}
