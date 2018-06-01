/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:39:39 by cbrill            #+#    #+#             */
/*   Updated: 2018/05/31 18:17:40 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../src/libft/libft.h"
# define ERROR_RETURN(i) { ft_putendl("error"); return (i); }

char	**make_pieces(unsigned int size);
void	unmake_tab(char **tab);
char	**make_board(unsigned int size);
int		could_place(char *board, int bsize, int pos, char *shape);
int		do_place(char *board, int bsize, int pos, char *shape);
int		unplace(char *board, int bsize, int pos, char *shape);

void	tetprint(char* tet);

int		ft_countch(const char *str, const unsigned char ch);
char	*ft_stripch(const char *str, unsigned int n, const unsigned char ch);
char	*ft_stripnl(const char *str);

void	ft_strfill(char *str, char c);
void	ft_strnfill(char *str, unsigned char c, unsigned int n);

void	ft_strshift(char *str, unsigned int n);
void	ft_strrevolve(char *str, unsigned int wide, unsigned int tall);

int		is_pattern(char* pattern);
void	read_pattern_file(const char *path, char *save[]);

#endif
