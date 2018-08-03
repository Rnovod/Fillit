/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creatlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:11:35 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/28 17:43:19 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fil		*ft_filnew(char *tmp)
{
	t_fil *new;

	if (!tmp)
		return (NULL);
	if (!(new = (t_fil*)malloc(sizeof(t_fil))))
		return (NULL);
	new->tetr = ft_strsplit(tmp, '\n');
	new->next = NULL;
	return (new);
}

t_fil		*ft_lstsplit(char *buff)
{
	t_fil	*p;
	t_fil	*begin;
	char	tmp[21];

	ft_strncpy(tmp, buff, 20);
	tmp[20] = '\0';
	buff += 20;
	if (!(p = ft_filnew(tmp)))
		return (NULL);
	begin = p;
	while (*buff++)
	{
		ft_bzero(tmp, 20);
		ft_strncpy(tmp, buff, 20);
		tmp[20] = '\0';
		if (!(p->next = ft_filnew(tmp)))
		{
			ft_free_lst(begin);
			return (NULL);
		}
		p = p->next;
		buff += 20;
	}
	return (begin);
}

void		ft_change_sharp(t_fil *p, char alpha)
{
	int	i;
	int	j;
	int x;

	x = 0;
	i = 0;
	while (p->tetr[i])
	{
		j = 0;
		while (p->tetr[i][j])
		{
			if (p->tetr[i][j] == '#')
			{
				p->coord[x][0] = i;
				p->coord[x++][1] = j;
				p->tetr[i][j] = alpha;
			}
			j++;
		}
		i++;
	}
}

t_fil		*ft_creatlst(char *buff)
{
	t_fil	*begin;
	t_fil	*p;
	char	alpha;

	if (!(begin = ft_lstsplit(buff)))
	{
		ft_putendl("error");
		return (NULL);
	}
	p = begin;
	alpha = 'A';
	while (p != NULL)
	{
		ft_change_sharp(p, alpha);
		p = p->next;
		alpha++;
	}
	return (begin);
}
