/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakatos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:44:41 by mlakatos          #+#    #+#             */
/*   Updated: 2018/02/13 10:44:48 by mlakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*l;

	if (lst != NULL && f != NULL)
	{
		if (lst->next)
		{
			l = ft_lstmap(lst->next, f);
			ft_lstadd(&l, f(lst));
		}
		else
		{
			l = f(lst);
		}
		return (l);
	}
	return (NULL);
}
