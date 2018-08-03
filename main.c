/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:08:03 by rnovodra          #+#    #+#             */
/*   Updated: 2017/12/01 14:23:10 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_open_read(char *namefile, char *buff)
{
	int	fd;
	int	ret;

	if ((fd = open(namefile, O_RDONLY)) == -1)
		return (-1);
	if ((ret = read(fd, buff, 546)) == -1)
		return (-1);
	buff[ret] = '\0';
	if (close(fd) == -1)
		return (-1);
	return (0);
}

void	ft_print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		ft_putendl(map[i++]);
}

int		ft_fillit(int ac, char *av)
{
	char	buff[546];
	t_fil	*begin;
	char	**map;

	if (ac != 2)
	{
		ft_putendl("usage: fillit target_file");
		return (-1);
	}
	if (ft_open_read(av, buff) == 0 && ft_valid(buff) == 0 &&
		(begin = ft_creatlst(buff)))
		if ((map = ft_algorithm(begin)))
		{
			ft_print_map(map);
			ft_free(map);
			ft_free_lst(begin);
			return (0);
		}
	ft_putendl("error");
	return (-1);
}

int		main(int ac, char **av)
{
	ft_fillit(ac, av[1]);
	return (0);
}
