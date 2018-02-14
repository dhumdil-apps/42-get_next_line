/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakatos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:57:31 by mlakatos          #+#    #+#             */
/*   Updated: 2018/02/13 18:07:16 by mlakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
	{
		return (1);
	}
	return (0);
}

static char	*fill_str(size_t size, char const *s, size_t x, size_t y)
{
	size_t	i;
	char	*str;

	i = 0;
	if ((str = (char *)malloc(size * sizeof(char))) != NULL)
	{
		if (size == 1)
		{
			str[i] = '\0';
		}
		else
		{
			while ((x + i) < y)
			{
				str[i] = s[x + i];
				i++;
			}
			str[i] = '\0';
		}
	}
	return (str);
}

char		*ft_strtrim(char const *s)
{
	char			*str;
	size_t			i;
	size_t			x;
	size_t			y;
	long long int	n;

	str = NULL;
	if (s != NULL)
	{
		i = 0;
		while (is_whitespace(s[i]))
			i++;
		x = i;
		while (s[i] != '\0')
			i++;
		while (is_whitespace(s[--i]) && i > 0)
			;
		y = i + 1;
		n = y - x;
		if (n <= 0)
			str = fill_str(1, "", 0, 0);
		else
			str = fill_str(n + 1, s, x, y);
	}
	return (str);
}
