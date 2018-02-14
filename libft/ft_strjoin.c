/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakatos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:53:09 by mlakatos          #+#    #+#             */
/*   Updated: 2018/02/13 13:14:38 by mlakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 != NULL && s2 != NULL)
	{
		if ((str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) != NULL)
		{
			ft_strcpy(str, s1);
			return (ft_strcat(str, s2));
		}
	}
	return (NULL);
}
