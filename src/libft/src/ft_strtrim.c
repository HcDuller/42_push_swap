/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:11:51 by hcduller          #+#    #+#             */
/*   Updated: 2021/06/03 17:15:14 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	match_chrset(char c, char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i[3];

	if (!s1 || !set)
		return (NULL);
	i[0] = 0;
	i[2] = ft_strlen(s1);
	i[1] = i[2] - 1;
	while (match_chrset(s1[i[0]], (char *)set) && i[0] < i[2])
		i[0]++;
	while (match_chrset(s1[i[1]], (char *)set) && i[1] > 0)
		i[1]--;
	if (i[1] > i[0])
		return (ft_substr(s1, i[0], i[1] - i[0] + 1));
	else
		return (ft_calloc(1, 1));
}

static int	match_chrset(char c, char *set)
{
	char	*ptr;

	ptr = set;
	while (*ptr)
	{
		if ((unsigned char)*ptr++ == (unsigned char)c)
			return (1);
	}
	return (0);
}
