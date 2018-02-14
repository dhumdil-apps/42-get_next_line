/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakatos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:52:32 by mlakatos          #+#    #+#             */
/*   Updated: 2018/02/13 10:52:36 by mlakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 != NULL && s2 != NULL)
	{
		if (ft_strcmp(s1, s2) == 0)
		{
			return (1);
		}
		return (0);
	}
	if ((s1 == NULL && s2 != NULL) || ((s1 != NULL && s2 == NULL)))
	{
		return (0);
	}
	return (1);
}
