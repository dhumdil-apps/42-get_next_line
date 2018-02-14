/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakatos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:05:15 by mlakatos          #+#    #+#             */
/*   Updated: 2018/02/13 11:05:19 by mlakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*l;
	t_list	*next;

	if (alst != NULL && *alst != NULL)
	{
		l = *alst;
		while (l)
		{
			next = l->next;
			del(l->content, l->content_size);
			free(l);
			l = next;
		}
		*alst = NULL;
	}
}
