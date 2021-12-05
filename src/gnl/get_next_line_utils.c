/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:44:03 by hcduller          #+#    #+#             */
/*   Updated: 2021/06/22 20:54:07 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*pre_break(char *str);
char	*pos_break(char *str);
int		has_break(char *p);

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;	

	ptr = malloc(count * size);
	if (ptr)
	{
		i = 0;
		while (i < (count * size))
		{
			((char *)ptr)[i] = (char)0;
			i++;
		}		
		return (ptr);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] && s[i] != '\0')
		{
			i++;
		}
	}
	return (i);
}

char	*pre_break(char *str)
{
	char	*aux;
	char	*new_str;

	aux = str;
	while (*aux && *aux != '\n')
		aux++;
	aux = (char *)ft_calloc((aux - str) + 1, 1);
	new_str = aux;
	if (!aux)
		return (NULL);
	while (*str && *str != '\n')
		*aux++ = *str++;
	return (new_str);
}

char	*pos_break(char *str)
{
	char	*break_index;
	char	*aux;
	char	*new_str;

	break_index = str;
	aux = str;
	new_str = NULL;
	while (*break_index && *break_index != '\n')
		break_index++;
	while (*aux)
		aux++;
	if ((aux - break_index) > 0)
	{
		new_str = (char *)ft_calloc((aux - break_index) + 1, 1);
		aux = new_str;
		while (*++break_index)
			*aux++ = *break_index;
	}
	free(str);
	return (new_str);
}

int	has_break(char *p)
{
	while (*p)
	{
		if ((unsigned char)*p == '\n')
			return (1);
		p++;
	}
	return (0);
}
