/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:05:48 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/05 15:57:49 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_space(char c)
{
	if ((unsigned char)c == 32)
		return (1);
	else if ((unsigned char)c >= 9 && (unsigned char)c <= 13)
		return (1);
	return (0);
}
