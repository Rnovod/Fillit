/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:10:40 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/15 14:51:20 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	size_t	ft_letters(char const *s, char c)
{
	int		letters;

	letters = 0;
	while (s[letters] != c && s[letters] != '\0')
		letters++;
	return (letters);
}

static	char	*ft_copy(char *dest, char const *s, size_t n)
{
	while (*s != '\0' && n--)
		*dest++ = *s++;
	*dest = '\0';
	return ((char*)s);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**r_s;
	size_t		i;
	size_t		words;

	i = 0;
	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(r_s = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	while (words > i)
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(r_s[i] = (char*)malloc(sizeof(char) * ft_letters(s, c) + 1)))
		{
			ft_free(r_s);
			return (NULL);
		}
		s = ft_copy(r_s[i++], s, ft_letters(s, c));
	}
	r_s[i] = NULL;
	return (r_s);
}
