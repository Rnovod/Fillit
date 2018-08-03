/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:50:46 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/29 14:50:47 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_free_lst(t_fil *begin)
{
	t_fil	*tmp;

	while (begin)
	{
		ft_free(begin->tetr);
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
	begin = NULL;
}
