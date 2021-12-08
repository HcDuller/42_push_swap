/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:06:12 by hde-camp          #+#    #+#             */
/*   Updated: 2021/12/08 20:31:06 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	unsigned_atoi(char *str, int *is_ok, int sign)
{
	long	r;
	long	max_value;

	r = 0;
	if (sign > 0)
		max_value = 2147483647;
	else
		max_value = 2147483648;
	if (*str != 0 && (*str < 48 || *str > 57))
	{
		*is_ok = 0;
		return (0);
	}
	while (*str)
	{
		r = r * 10 + (*str++ - 48);
		if ((*str != 0 && (*str < 48 || *str > 57)) || r > max_value)
		{
			*is_ok = 0;
			return (0);
		}
	}
	return ((int)r);
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
		r = unsigned_atoi(str, is_ok, fat);
		return (r * fat);
	}
	*is_ok = 0;
	return (0);
}
