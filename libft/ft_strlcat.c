/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakatos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:53:21 by mlakatos          #+#    #+#             */
/*   Updated: 2018/02/13 16:09:08 by mlakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = 0;
	while (dest[dest_len] && dest_len < n)
		dest_len++;
	if (dest_len == n)
		return (n + src_len);
	i = dest_len;
	while (i < (n - 1) && src[i - dest_len])
	{
		dest[i] = src[i - dest_len];
		i++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}
