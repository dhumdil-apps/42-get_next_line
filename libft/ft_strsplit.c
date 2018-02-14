/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakatos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:56:21 by mlakatos          #+#    #+#             */
/*   Updated: 2018/02/13 14:52:57 by mlakatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_init(char const *s, char c, long int *i, long int *n)
{
	long int	tmp_i;
	long int	tmp_n;
	int			is_word;

	tmp_i = 0;
	tmp_n = 0;
	is_word = 0;
	while (s[tmp_i] != '\0')
	{
		if (s[tmp_i] == c)
		{
			is_word = 0;
		}
		else if (is_word == 0)
		{
			is_word = 1;
			tmp_n++;
		}
		tmp_i++;
	}
	*i = 0;
	*n = tmp_n;
	return (NULL);
}

static long int	ft_size(char *s, char c)
{
	long int	i;
	long int	n;

	i = 0;
	while (s[i] == c)
	{
		i++;
	}
	n = i;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i - n);
}

static void		ft_fill(char *m_i, char *s, char c)
{
	long int	i;
	long int	j;

	i = 0;
	while (s[i] == c)
	{
		i++;
	}
	j = 0;
	while (s[i + j] != c && s[i + j] != '\0')
	{
		m_i[j] = s[i + j];
		s[i + j] = c;
		j++;
	}
	m_i[j] = '\0';
}

char			**ft_strsplit(char const *s, char c)
{
	char		**m;
	char		*str;
	long int	i;
	long int	n;

	m = ft_init(s, c, &i, &n);
	if (s && (str = ft_strnew(ft_strlen(s))))
	{
		ft_strcpy(str, s);
		if ((m = (char **)malloc((n + 1) * sizeof(char *))))
		{
			while (i < n)
			{
				if (!(m[i] = ft_strnew(ft_size(str, c))))
				{
					return (NULL);
				}
				ft_fill(m[i], str, c);
				i++;
			}
			m[i] = NULL;
		}
	}
	return (m);
}
