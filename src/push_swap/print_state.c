/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:50:20 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/16 18:17:54 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_state(t_p_swap state)
{
	char	*str;

	str = ft_itoa(state.moves);
	ft_putstr_fd("[a]:\t", 1);
	print_stack(state.a);
	ft_putstr_fd("[b]:\t", 1);
	print_stack(state.b);
	ft_putstr_fd("Total moves so far:\t", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	free(str);
}
