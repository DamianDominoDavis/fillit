/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:39:39 by cbrill            #+#    #+#             */
/*   Updated: 2018/06/17 17:50:24 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_etris
{
	char		*str;
	int			w;
	int			h;
	int			x[4];
	int			y[4];
	char		id;
}				t_etris;

int		nope(char *msg, int fd, int rvalue);
int		readpieces(int fd, t_etris *pieces[]);
int		ispattern(char *p);
void	makepiece(char *pattern, t_etris *t, char id);
void	sizepiece(t_etris *t);
void	ft_strrevolve(char *str, unsigned int wide, unsigned int tall);
void	tetprint(t_etris *t);
char	**solve(t_etris *pieces[]);
char	**makeboard(char **board, int size);
void	resizeboard(char **board, int size);
int		solveboard(char **board, t_etris *pieces[], int i);
int		canplace(t_etris *t, char **board, int x, int y);
int		hasneighbor(char **board, int x, int y);
void	replace(t_etris *t, char **map, int x, int y);
void	place(t_etris *t, char **map, int x, int y);
void	unplace(t_etris *t, char **map, int x, int y);
void	free_tetris(t_etris *tetri);
int		ft_countch(const char *str, const unsigned char ch);
char	*ft_stripch(const char *str, unsigned int n, const unsigned char ch);
void	ft_strshift(char *str, unsigned int n);
void	printboard(char **board);

#endif
