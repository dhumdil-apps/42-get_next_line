/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakatos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:39:44 by mlakatos          #+#    #+#             */
/*   Updated: 2018/02/13 10:57:16 by mlakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s != NULL)
	{
		i = 0;
		str = ft_strnew(len);
		if (str != NULL)
		{
			while (len - i)
			{
				str[i] = s[start + i];
				i++;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
