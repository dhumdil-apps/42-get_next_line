/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakatos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:05:47 by mlakatos          #+#    #+#             */
/*   Updated: 2018/02/13 12:28:56 by mlakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((n - i) > 0)
	{
		if (src[j] != '\0')
		{
			dest[i] = src[j];
			j++;
		}
		else
		{
			dest[i] = '\0';
		}
		i++;
	}
	return (dest);
}
