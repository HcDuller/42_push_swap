/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:06:12 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/09 14:28:57 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	strict_atoi(char *str, int *is_ok)
{
	int	r;	
	int	fat;

	r = 0;
	fat = 1;
	*is_ok = 1;
	if (*str)
	{
		while (is_space(*str))
			str++;
		if (*str == 43 || *str == 45)
			if (*str++ == 45)
				fat = -1;
		while (*str)
		{
			r = r * 10 + (*str++ - 48);
			if (*str != 0 && (*str < 48 || *str > 57))
			{
				*is_ok = 0;
				return 0;
			}
		}
		return (r * fat);
	}
	*is_ok = 0;
	return (0);
}
