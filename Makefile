# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 17:00:59 by rnovodra          #+#    #+#              #
#    Updated: 2017/12/04 14:18:14 by rnovodra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

MAIN = validation.o \
		main.o creatlst.o backtracking.o \
		ft_free_lst.o ft_algorithm.o \
		ft_mapmalloc.o 

OBJ = ft_strncpy.o \
	ft_bzero.o \
	ft_strsplit.o \
	ft_memset.o \
	ft_putendl.o \
	ft_free.o \
	ft_count_words.o 

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(MAIN) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(MAIN) 

%.o : %.c
	gcc -c -o $@ $< $(FLAGS)

clean :
	rm -rf $(OBJ)
	rm -rf $(MAIN)

fclean : clean
	rm -rf $(NAME) 

re : fclean all

.PHONY: all fclean clean re 
