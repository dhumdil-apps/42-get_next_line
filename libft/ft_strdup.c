/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakatos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:58:13 by mlakatos          #+#    #+#             */
/*   Updated: 2018/02/13 13:11:22 by mlakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	if ((str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))) != NULL)
	{
		return (ft_strcpy(str, s));
	}
	return (NULL);
}
