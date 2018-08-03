/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:38:48 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/29 15:58:02 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_addtetr(t_fil *p, char **map, int i, int j)
{
	int x;
	int nav_x;
	int nav_y;

	x = 0;
	map[i][j] = p->tetr[p->coord[x][0]][p->coord[x][1]];
	while (x++ < 3)
	{
		nav_x = (p->coord[x][0] - p->coord[x - 1][0]);
		nav_y = (p->coord[x][1] - p->coord[x - 1][1]);
		map[i += nav_x][j += nav_y] = p->tetr[p->coord[x][0]][p->coord[x][1]];
	}
}

int		ft_checkinmap(t_fil *p, char **map, int i, int j)
{
	int x;
	int okey;
	int nav_x;
	int nav_y;

	x = 0;
	okey = 0;
	if (map[i] == NULL)
		return (-2);
	okey += (map[i][j] == '.');
	while (x++ < 3)
	{
		nav_x = (p->coord[x][0] - p->coord[x - 1][0]);
		nav_y = (p->coord[x][1] - p->coord[x - 1][1]);
		okey += (j + nav_y >= 0 &&
				map[i + nav_x] != NULL &&
				map[i][j + nav_y] != '\0' &&
				map[i += nav_x][j += nav_y] == '.');
	}
	if (okey != 4)
		return (-1);
	return (0);
}

int		ft_check_add(char **map, t_fil *p, int i, int j)
{
	if (ft_checkinmap(p, map, i, j) == 0)
	{
		ft_addtetr(p, map, i, j);
		return (0);
	}
	return (-1);
}

void	ft_delete_tetr(t_fil *p, char **map, int i, int j)
{
	int x;
	int nav_x;
	int nav_y;

	x = 0;
	map[i][j] = '.';
	while (x++ < 3)
	{
		nav_x = (p->coord[x][0] - p->coord[x - 1][0]);
		nav_y = (p->coord[x][1] - p->coord[x - 1][1]);
		map[i += nav_x][j += nav_y] = '.';
	}
}

int		ft_backtr_re(t_fil *p, char **map, int i, int j)
{
	int flag;

	flag = 0;
	while (map && map[i] != NULL && p)
	{
		while (map[i][++j] != '\0')
		{
			if (ft_check_add(map, p, i, j) == 0)
			{
				flag = 1;
				if (ft_backtr_re(p->next, map, 0, -1) == -1)
				{
					flag = 0;
					ft_delete_tetr(p, map, i, j);
				}
				else if (p)
					return (0);
			}
		}
		j = -1;
		i++;
	}
	if (flag == 0 && p)
		return (-1);
	return (0);
}
