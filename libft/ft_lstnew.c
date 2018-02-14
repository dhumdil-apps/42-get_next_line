/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakatos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:44:54 by mlakatos          #+#    #+#             */
/*   Updated: 2018/02/13 10:44:59 by mlakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*l;

	if ((l = (t_list *)malloc(sizeof(t_list))) != NULL)
	{
		if (content == NULL)
		{
			l->content = NULL;
			l->content_size = 0;
			l->next = NULL;
			return (l);
		}
		else
		{
			l->content = malloc(content_size);
			if (l->content != NULL)
			{
				ft_memmove(l->content, content, content_size);
				l->content_size = content_size;
				l->next = NULL;
				return (l);
			}
		}
	}
	return (NULL);
}
