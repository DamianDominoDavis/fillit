/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 15:59:09 by cbrill            #+#    #+#             */
/*   Updated: 2018/06/17 17:47:41 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**solve(t_etris *pieces[])
{
	char	**board;
	int		size;
	int		count;

	count = 0;
	while (pieces[count]->str)
		count++;
	size = 2;
	while (size * size < count * 4)
		size++;
	board = makeboard(NULL, size);
	while (!solveboard(board, pieces, 0))
		resizeboard(board, ++size);
	return (board);
}

int		solveboard(char **board, t_etris *pieces[], int i)
{
	int			x;
	int			y;
	int			size;

	if (pieces[i] == NULL || pieces[i]->str == NULL)
		return (1);
	size = ft_strlen(board[0]);
	y = -1;
	while (++y + pieces[i]->h <= size)
	{
		x = -1;
		while (++x + pieces[i]->w <= size)
		{
			if (canplace(pieces[i], board, x, y))
			{
				place(pieces[i], board, x, y);
				if (solveboard(board, pieces, i + 1))
					return (1);
				else
					unplace(pieces[i], board, x, y);
			}
		}
	}
	return (0);
}

int		canplace(t_etris *t, char **board, int x, int y)
{
	int i;
	int size;

	size = ft_strlen(board[0]);
	i = -1;
	while (++i < 4)
		if (x + t->x[i] >= size || y + t->y[i] >= size
			|| board[y + t->y[i]][x + t->x[i]] != '.')
			return (0);
	return (1);
}

void	place(t_etris *t, char **board, int x, int y)
{
	int i;

	i = -1;
	while (++i < 4)
		board[y + t->y[i]][x + t->x[i]] = t->id;
}

void	unplace(t_etris *t, char **board, int x, int y)
{
	int i;

	i = -1;
	while (++i < 4)
		board[y + t->y[i]][x + t->x[i]] = '.';
}
