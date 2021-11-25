/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:27:30 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/05 15:27:32 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_stack(t_stack stack)
{
	int		i;
	char	*str;

	i = stack.top;
	while (i >= 0)
	{
		str = ft_itoa(stack.stack[i]);
		i--;
		ft_putstr_fd(str, 1);
		if (i >= 0)
			ft_putstr_fd("->", 1);
		if (str)
			free(str);
	}
	ft_putstr_fd("\n", 1);
}
