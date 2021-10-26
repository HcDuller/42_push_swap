/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 22:08:30 by hcduller          #+#    #+#             */
/*   Updated: 2021/06/09 11:31:32 by hcduller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static	size_t	occ_count(char const *s, char c);
static	void		splitter(char *s, char c, char **aptr);

char	**ft_split(char const *s, char c)
{
	char	**ar_ptr;
	size_t	i;

	ar_ptr = NULL;
	if (s)
	{
		i = occ_count(s, c);
		ar_ptr = (char **)ft_calloc(i + 1, sizeof (char *));
		if (!ar_ptr)
			return (NULL);
		splitter((char *)s, c, ar_ptr);
	}
	return (ar_ptr);
}

size_t	occ_count(char const *s, char c)
{
	char	*pf;
	size_t	i;

	pf = (char *)s;
	i = 0;
	while (*pf)
	{
		if (*pf != c)
		{
			while (*pf != c && *pf)
				pf++;
			i++;
		}
		if (*pf)
			pf++;
	}
	return (i);
}

void	splitter(char *s, char c, char **aptr)
{
	size_t	i;
	size_t	n;

	n = 0;
	while (*s)
	{
		i = 0;
		if (*s != c)
		{
			while (s[i] != c && s[i])
			{				
				i++;
			}
			aptr[n++] = ft_substr(s, 0, i);
			s += i - 1;
		}
		if (*s)
			s++;
	}
}
