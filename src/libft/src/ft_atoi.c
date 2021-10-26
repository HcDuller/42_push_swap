/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:38:11 by hcduller          #+#    #+#             */
/*   Updated: 2021/05/31 15:07:51 by hcduller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	breaking_character(char c, int i)
{
	if (i == 1)
	{
		if ((unsigned char)c == 43 || (unsigned char)c == 45)
			return (1);
	}
	if ((unsigned char)c <= 8)
		return (1);
	if ((unsigned char)c >= 14 && (unsigned char)c <= 31)
		return (1);
	if ((unsigned char)c >= 33 && (unsigned char)c <= 42)
		return (1);
	if ((unsigned char)c >= 46 && (unsigned char)c <= 47)
		return (1);
	if ((unsigned char)c == 44)
		return (1);
	if ((unsigned char)c > 57)
		return (1);
	return (0);
}

int	is_space(char c)
{
	if ((unsigned char)c == 32)
		return (1);
	else if ((unsigned char)c >= 9 && (unsigned char)c <= 13)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	r;	
	int	fat;

	r = 0;
	fat = 1;
	while (*nptr)
	{		
		while (is_space(*nptr))
			nptr++;
		if (breaking_character(*nptr, 0))
			return (0);
		if (*nptr == 43 || *nptr == 45)
		{
			if (*nptr++ == 45)
				fat = -1;
		}
		while (!(breaking_character(*nptr, 1)) && !is_space(*nptr))
		{
			r = r * 10 + (*nptr++ - 48);
			if (breaking_character(*nptr, 1) || is_space(*nptr))
				return (fat * r);
		}
		return (0);
	}
	return (0);
}
