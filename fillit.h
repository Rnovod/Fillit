/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:01:21 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/28 12:22:13 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>

typedef	struct		s_fil
{
	char			**tetr;
	int				coord[4][2];
	struct s_fil	*next;
}					t_fil;

int					ft_valid(char *buff);
t_fil				*ft_creatlst(char *buff);
char				**ft_algorithm(t_fil *begin);
void				ft_free_lst(t_fil *begin);
char				**ft_mapmalloc(int n);
char				**ft_algorithm(t_fil *begin);
int					ft_backtr_re(t_fil *p, char **map, int i, int j);

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				**ft_strsplit(char const *s, char c);
void				ft_putendl(char const *s);
void				ft_free(char **array);
size_t				ft_count_words(char const *s, char c);

#endif
