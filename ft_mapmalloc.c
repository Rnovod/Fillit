/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:03:48 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/29 16:03:49 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_mapmalloc(int n)
{
	int		i;
	char	**map;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	while (n > i)
		if (!(map[i++] = (char*)malloc(sizeof(char) * (n + 1))))
		{
			ft_free(map);
			return (NULL);
		}
	map[i] = NULL;
	while (i--)
	{
		ft_memset(map[i], '.', n);
		map[i][n] = '\0';
	}
	return (map);
}
