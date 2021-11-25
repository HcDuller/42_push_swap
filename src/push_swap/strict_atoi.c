/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:06:12 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/25 18:44:16 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	unsigned_atoi(char *str, int *is_ok)
{
	int	r;

	r = 0;
	while (*str)
	{
		r = r * 10 + (*str++ - 48);
		if (*str != 0 && (*str < 48 || *str > 57))
		{
			*is_ok = 0;
			return (0);
		}
	}
	return (r);
}

int	strict_atoi(char *str, int *is_ok)
{
	int	r;	
	int	fat;

	fat = 1;
	*is_ok = 1;
	if (*str)
	{
		while (is_space(*str))
			str++;
		if (*str == 43 || *str == 45)
			if (*str++ == 45)
				fat = -1;
		r = unsigned_atoi(str, is_ok);
		return (r * fat);
	}
	*is_ok = 0;
	return (0);
}
