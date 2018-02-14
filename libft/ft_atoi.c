/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakatos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:37:47 by mlakatos          #+#    #+#             */
/*   Updated: 2018/02/14 19:02:52 by mlakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	size_t			i;
	int				is_minus;
	long long int	value;

	i = 0;
	is_minus = 0;
	value = 0;
	while (ft_is_whitespace(s[i]))
		i++;
	if (s[i] == '+')
	{
		i++;
	}
	else if (s[i] == '-')
	{
		is_minus = 1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		value = (value * 10) + (s[i++] - '0');
	}
	if (is_minus)
		return ((int)(-value));
	return ((int)(value));
}
