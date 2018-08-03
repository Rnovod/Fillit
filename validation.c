/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:09:06 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/29 19:32:09 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_first_step_valid(char *buff)
{
	int i;

	i = 0;
	if (buff[0] == '\0')
		return (-1);
	while (buff[i] != '\0')
	{
		if (buff[i] != '#' && buff[i] != '.' && buff[i] != '\n')
			return (-1);
		i++;
	}
	return (0);
}

int		ft_second_step_valid(char *buff)
{
	int i;
	int line;
	int len;

	len = 0;
	i = 0;
	line = 0;
	while (buff[i] != '\0')
	{
		while (buff[i++] != '\n' && buff[i] != '\0')
			len++;
		if (len != 4)
			return (-1);
		len = 0;
		line++;
		if (buff[i] == '\n' && line == 4)
		{
			line = 0;
			if (buff[i + 1] != '\0')
				i++;
		}
		else if ((buff[i] == '\n' || buff[i] == '\0') && line != 4)
			return (-1);
	}
	return (0);
}

int		ft_third_step_valid(char *buff)
{
	int i;
	int sharp;

	sharp = 0;
	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '#')
			sharp++;
		if (buff[i] == '\n' && (buff[i + 1] == '\n' || buff[i + 1] == '\0'))
		{
			if (sharp != 4)
				return (-1);
			sharp = 0;
			i++;
		}
		if (buff[i] != '\0')
			i++;
	}
	return (0);
}

int		ft_last_step_valid(char *buff)
{
	int i;
	int connect;

	connect = 0;
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
		{
			connect += (i - 1 >= 0 && buff[i - 1] == '#');
			connect += (i - 5 >= 0 && buff[i - 5] == '#');
			connect += (buff[i + 1] == '#');
			connect += (i + 5 < 20 && buff[i + 5] == '#');
		}
		i++;
	}
	if (connect > 5)
		return (0);
	return (-1);
}

int		ft_valid(char *buff)
{
	char	tmp[21];
	int		tetriminoes;

	tetriminoes = 0;
	if (ft_first_step_valid(buff) == -1)
		return (-1);
	if (ft_second_step_valid(buff) == -1)
		return (-1);
	if (ft_third_step_valid(buff) == -1)
		return (-1);
	while (*buff)
	{
		ft_strncpy(tmp, buff, 20);
		tmp[20] = '\0';
		if (ft_last_step_valid(tmp) == -1)
			return (-1);
		ft_bzero(tmp, 21);
		if (++tetriminoes > 26)
			return (-1);
		if (*(buff += 20) != '\0')
			buff++;
	}
	return (0);
}
