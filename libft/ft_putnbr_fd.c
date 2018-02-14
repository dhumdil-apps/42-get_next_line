/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakatos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:49:50 by mlakatos          #+#    #+#             */
/*   Updated: 2018/02/13 13:33:09 by mlakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_abs(long long int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		return (-n);
	}
	return (n);
}

static void				ft_print_n(long long int n, int fd)
{
	if (n > 0)
	{
		ft_print_n(n / 10, fd);
		ft_putchar_fd('0' + (n % 10), fd);
	}
}

void					ft_putnbr_fd(int nb, int fd)
{
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
	}
	else
	{
		ft_print_n(ft_abs(nb, fd), fd);
	}
}
