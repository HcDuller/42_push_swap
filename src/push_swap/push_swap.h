/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:54:01 by hde-camp          #+#    #+#             */
/*   Updated: 2021/11/04 11:35:08 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

typedef struct s_stack
{
	int	*stack;
	int	top;
	int	size;
} t_stack;

typedef struct s_p_swap
{
	t_stack	a;
	t_stack	b;
} t_p_swap;