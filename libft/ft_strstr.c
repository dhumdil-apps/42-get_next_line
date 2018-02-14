/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakatos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:50:47 by mlakatos          #+#    #+#             */
/*   Updated: 2018/02/13 12:35:19 by mlakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *substring)
{
	size_t	i;
	size_t	j;

	if (substring[0] == '\0')
	{
		return ((char *)s);
	}
	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i + j] == substring[j] || substring[j] == '\0')
		{
			if (substring[j++] == '\0')
			{
				return ((char *)s + i);
			}
		}
		i++;
	}
	return (NULL);
}
