/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 15:54:33 by cbrill            #+#    #+#             */
/*   Updated: 2018/06/17 17:47:19 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		readpieces(int fd, t_etris *pieces[])
{
	char	candidate[21];
	int		count;
	int		rcount;

	candidate[20] = '\0';
	count = 0;
	if (fd < 0)
		return (0);
	while (count <= 26 && (rcount = read(fd, candidate, 20)) == 20)
	{
		if (ispattern(candidate))
			makepiece(candidate, pieces[count], count);
		else
			return (0);
		count++;
		rcount = read(fd, candidate, 1);
		if (rcount == 1 && candidate[0] != '\n')
			return (0);
	}
	return ((rcount == 0) ? count : 0);
}

int		ispattern(char *p)
{
	int	x;
	int	c;
	int	h;

	if (p[4] != '\n' || p[4] != '\n' || p[9] != '\n')
		return (0);
	x = -1;
	c = 0;
	h = 0;
	while (++x < 20)
	{
		if (p[x] != '#' && p[x] != '.' && p[x] != '\n' && p[x] != '\0')
			return (0);
		if (p[x] == '#')
		{
			h++;
			c += (x < 20 && p[x] == p[x + 1]) + (x > 0 && p[x] == p[x - 1])
				+ (x + 5 <= 20 && p[x] == p[x + 5])
				+ (x - 5 >= 0 && p[x] == p[x - 5]);
		}
	}
	if (h != 4 || (c != 6 && c != 8))
		return (0);
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
	int quad;
	int max[2];

	i = -1;
	quad = 0;
	while (++i < 16)
		if (t->str[i] == '#')
		{
			t->x[quad] = i % 4;
			t->y[quad] = i / 4;
			quad++;
		}
	max[0] = 0;
	max[1] = 0;
	i = -1;
	while (++i < 4)
	{
		max[0] = (max[0] < t->x[i]) ? t->x[i] : max[0];
		max[1] = (max[1] < t->y[i]) ? t->y[i] : max[1];
	}
	t->w = max[0] + 1;
	t->h = max[1] + 1;
}
