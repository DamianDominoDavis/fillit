/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 15:57:57 by cbrill            #+#    #+#             */
/*   Updated: 2018/06/17 17:47:24 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**makeboard(char **board, int size)
{
	int		i;
	int		j;
	int		maxp;

	maxp = 100;
	board = (char **)ft_memalloc(sizeof(char*) * (maxp + 1));
	i = 0;
	while (i <= maxp)
	{
		board[i] = ft_strnew(maxp);
		j = 0;
		while (j < maxp)
		{
			board[i][j] = (i < size && j < size) ? '.' : '\0';
			j++;
		}
		i++;
	}
	return (board);
}

void	resizeboard(char **board, int size)
{
	int x;
	int y;
	int maxp;

	maxp = 100;
	y = -1;
	while (++y <= maxp)
	{
		x = -1;
		while (++x <= maxp)
		{
			board[y][x] = (y < size && x < size) ? '.' : '\0';
		}
	}
}

void	printboard(char **board)
{
	int i;
	int size;

	size = ft_strlen(board[0]);
	i = -1;
	while (++i < size)
		ft_putendl(board[i]);
}
