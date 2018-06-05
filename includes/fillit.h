/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:39:39 by cbrill            #+#    #+#             */
/*   Updated: 2018/06/04 13:57:03 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "../src/libft/libft.h"
//REMOVE LATER
# include <stdio.h>

typedef struct	s_etris
{
	char		*str;
	int			w;
	int			h;
	int			x;
	int			y;
}				t_etris;

int		nope(char *msg, int fd, int rvalue);
int		main(int c, char **v);
int		readpieces(int fd, t_etris *pieces[]);
int		ispattern(char *pattern);
t_etris	*makepiece(char *pattern);
void	sizepiece(t_etris *t);

void	ft_strshift(char *str, unsigned int n);
void	ft_strrevolve(char *str, unsigned int wide, unsigned int tall);
char	*ft_stripnl(const char *str);
char	*ft_stripch(const char *str, unsigned int n, const unsigned char ch);
int		ft_countch(const char *str, const unsigned char ch);
void	tetprint(t_etris *t);

#endif
