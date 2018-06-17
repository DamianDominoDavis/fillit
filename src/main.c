/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:51:01 by cbrill            #+#    #+#             */
/*   Updated: 2018/06/17 15:12:03 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		nope(char *msg, int fd, int rvalue)
{
	ft_putendl_fd(msg, fd);
	return (rvalue);
}

int		main(int c, char **v)
{
	t_etris	*pieces[27];
	int		i;
	char	**board;

	if (c != 2)
		return nope("usage: fillit patterns.txt", 1, 0);
	i = -1;
	while (++i < 27)
	{
		if (!(pieces[i] = (t_etris*)ft_memalloc(sizeof(t_etris))))
			return nope("main: OOM", 2, 0);
		pieces[i]->str = NULL;
	}
	if ((readpieces(open(v[1], O_RDONLY), pieces)) == 0)
		return nope("fillit: could not read pieces", 2, 0);
	board = solve(pieces);
	printboard(board);
	return (0);
}

int		readpieces(int fd, t_etris *pieces[])
{
	char	candidate[21];
	int		count;
	int		rcount;

	candidate[20] = '\0';
	count = 0;
	if (fd < 0)
		return nope("readpieces: couldn't read file.", 2, 0);
	while (count <= 26 && (rcount = read(fd, candidate, 20)) == 20)
	{
		if (ispattern(candidate))
		{
			makepiece(candidate, pieces[count], count);
			count++;
		}
		else
			return nope("readpieces: pattern format error", 2, 0);
		rcount = read(fd, candidate, 1);
		if (rcount == 1 && candidate[0] != '\n')
			return nope("readpieces: file format error", 2, 0);
	}
	return ((rcount == 0) ? count : nope("readpieces: unexpected EoF", 2, 0));
}

int		ispattern(char *p)
{
	int x;
	int c;
    int h;

	if (p[4] != '\n' || p[4] != '\n' || p[9] != '\n')
		return nope("ispattern: not a shape (bad format)", 2, 0);
	x = -1;
	c = 0;
    h = 0;
	while (++x < 20)
	{
		if (p[x] != '#' && p[x] != '.' && p[x] != '\n' && p[x] != '\0')
			return nope("ispattern: unknown symbol", 2, 0);
		if (p[x] == '#')
        {
            h++;
            if (x < 20 && p[x] == p[x + 1])
                c++;
            if (x > 0 && p[x] == p[x - 1])
                c++;
            if (x + 5 <= 20 && p[x] == p[x + 5])
                c++;
            if (x - 5 >= 0 && p[x] == p[x - 5])
                c++;
        }
	}
	if (!(c == 6 || c == 8) || !(h == 4))
		return nope("ispattern: not a shape", 2, 0);
	return (1);
}

void	makepiece(char *pattern, t_etris *t, char id)
{
	while (ft_strchr(pattern, '#') - &pattern[0] >= 4)
		ft_strshift(pattern, 5);
	while (pattern[0] != '#' && pattern[5] != '#' && pattern[10] != '#'
		&& pattern[15] != '#')
		ft_strrevolve(pattern, 5, 4);
	t->str = ft_strdup(ft_stripch(pattern, ft_strlen(pattern), '\n'));
	sizepiece(t);
	t->id = 'A' + id;
}

void	sizepiece(t_etris *t)
{
	int i;
	int corners[4];
	int k;

	corners[0] = 3;
	corners[1] = 0;
	corners[2] = 3;
	corners[3] = 0;
	i = -1;
	while (++i < 4)
	{
		t->x[i] = 0;
		t->y[i] = 0;
	}
	i = -1;
	k = 0;
	while (++i < 16)
		if (t->str[i] == '#')
		{
			t->x[k] = i % 4;
			t->y[k] = i / 4;
			corners[0] = (t->x[k] < corners[0]) ? t->x[k] : corners[0];
			corners[1] = (t->x[k] > corners[1]) ? t->x[k] : corners[1];
			corners[2] = (t->y[k] < corners[2]) ? t->y[k] : corners[2];
			corners[3] = (t->y[k] > corners[3]) ? t->y[k] : corners[3];
			k++;
		}
	t->w = 1 + corners[1] - corners[0];
	t->h = 1 + corners[3] - corners[2];
}

void	ft_strrevolve(char *str, unsigned int wide, unsigned int tall)
{
	unsigned int row;
	unsigned int w;
	char tmp;

	row = -1;
	while (++row < tall)
	{
		tmp = str[row * wide];
		w = -1;
		while (++w < wide - 1)
			str[row * wide + w] = str[row * wide + w + 1];
		str[row * wide + wide - 1] = tmp;
	}
}

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

char	**makeboard(char **board, int size)
{
	int		i;
	int		j;
	int		maxp;

	maxp = 100;
	board = (char **)ft_memalloc(sizeof(char *) * (maxp + 1));
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

int		solveboard(char **board, t_etris *pieces[], int i)
{
	int			x;
	int			y;
	int			size;

	if (pieces[i] == NULL || pieces[i]->str == NULL)
		return (1);
	size = ft_strlen(board[0]);
	y = 0;
	while (y + pieces[i]->h <= size)
	{
		x = 0;
		while (x + pieces[i]->w <= size)
		{
			if (canplace(pieces[i], board, x, y))
			{
			  	place(pieces[i], board, x, y);
				if (solveboard(board, pieces, i + 1))
					return (1);
				else
				{
					unplace(pieces[i], board, x, y);
				}
			}
			x++;
		}
		y++;
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
	{
		if (board[y + t->y[i]][x + t->x[i]] != '.')
			printf("place is overwriting existing pieces\n");
		board[y + t->y[i]][x + t->x[i]] = t->id;
	}
}

void	unplace(t_etris *t, char **board, int x, int y)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (board[y + t->y[i]][x + t->x[i]] == '.')
			printf("unplace is clearing empty board pos\n");
		board[y + t->y[i]][x + t->x[i]] = '.';
	}
}

void	free_tetris(t_etris *t)
{
	ft_strdel(&t->str);
	ft_memdel((void **)&t);
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
