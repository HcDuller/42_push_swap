/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcduller <hcduller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:48:23 by hcduller          #+#    #+#             */
/*   Updated: 2021/06/02 16:32:11 by hcduller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	mod(int n);
static	void	ft_putnbr_aux(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putnbr_aux(n, fd);
}

static	void	ft_putnbr_aux(int n, int fd)
{
	if (n / 10 != 0)
		ft_putnbr_aux(n / 10, fd);
	ft_putchar_fd(mod(n % 10) + 48, fd);
}

int	mod(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
