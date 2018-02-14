/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakatos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:43:18 by mlakatos          #+#    #+#             */
/*   Updated: 2018/02/14 19:05:29 by mlakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_abs(long int n)
{
	if (n < 0)
	{
		return (-n);
	}
	return (n);
}

static size_t	count_length(long int n)
{
	size_t	i;

	if (n == 0)
	{
		i = 1;
	}
	else
	{
		i = 0;
		while (n > 0)
		{
			n /= 10;
			i++;
		}
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*s;
	size_t		i;
	long int	m;

	i = 0;
	if (n < 0)
		i++;
	m = ft_abs(n);
	i += count_length(m);
	if ((s = ft_strnew(i)) != NULL)
	{
		if (m == 0)
			s[0] = '0';
		else
		{
			while (m > 0)
			{
				s[--i] = '0' + (m % 10);
				m /= 10;
			}
			if (i > 0)
				s[0] = '-';
		}
	}
	return (s);
}
