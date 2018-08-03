/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:06:07 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/29 16:06:10 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_algorithm(t_fil *begin)
{
	int		n;
	char	**map;

	n = 2;
	map = ft_mapmalloc(n);
	while (ft_backtr_re(begin, map, 0, -1) == -1)
	{
		ft_free(map);
		map = ft_mapmalloc(++n);
	}
	return (map);
}
