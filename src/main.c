/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiandavis <damiandavis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:51:01 by cbrill            #+#    #+#             */
/*   Updated: 2018/06/04 23:22:44 by damiandavis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		nope(char *msg, int fd, int rvalue)
{
	write(fd, msg, ft_strlen(msg));
	write(fd, "\n", 1);
	return (rvalue);
}

int		main(int c, char **v)
{
	int		count;
	t_etris	*pieces[26];
	int		i;

	if (c != 2)
		return nope("usage: fillit patterns.txt", 1, 0);
	i = 0;
	while (i < 26)
		pieces[i++] = NULL;
	if ((count = readpieces(open(v[1], O_RDONLY), pieces)) == 0)
		return nope("fillit: could not read pieces", 2, 0);
	i = 0;
	while (pieces[i])
		tetprint(pieces[i++]);
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
	while ((rcount = read(fd, candidate, 20)) == 20)
	{
		if (ispattern(candidate))
				pieces[count++] = makepiece(candidate);
		else
			return nope("readpieces: pattern format error", 2, 0);
		rcount = read(fd, candidate, 1);
		if (rcount == 1 && candidate[0] != '\n')
			return nope("readpieces: file format error", 2, 0);
	}
	return (count);
}

int		ispattern(char *p)
{
	int x;
	int n;

	if (p[4] != '\n' || p[4] != '\n' || p[9] != '\n')
		return nope("ispattern: not a shape (bad format)", 2, 0);
	x = -1;
	n = 0;
	while (++x < 20)
	{
		if (p[x] != '#' && p[x] != '.' && p[x] != '\n' && p[x] != '\0')
			return nope("ispattern: unknown symbol", 2, 0);
		if (p[x] == '#' && x < 20 && p[x] == p[x + 1])
			n++;
		if (p[x] == '#' && x > 0 && p[x] == p[x - 1])
			n++;
		if (p[x] == '#' && x + 5 <= 20 && p[x] == p[x + 5])
			n++;
		if (p[x] == '#' && x - 5 >= 0 && p[x] == p[x - 5])
			n++;
	}
	if (n != 6 && n != 8)
		return nope("ispattern: not a shape (bad connection)", 2, 0);
	return (1);
}

t_etris	*makepiece(char *pattern)
{
	t_etris	*out;

	//we don't actually need this, now sizepiece works
	//still might speed up execution time during backtrack, can't prove it
	while (ft_strchr(pattern, '#') - &pattern[0] >= 4)
		ft_strshift(pattern, 5);
	while (pattern[0] != '#' && pattern[5] != '#' && pattern[10] != '#'
		&& pattern[15] != '#')
		ft_strrevolve(pattern, 5, 4);
	//end note
	out = (t_etris*)malloc(sizeof(t_etris*));
	out->str = ft_stripnl(pattern);
	sizepiece(out);
	return (out);
}

void	sizepiece(t_etris *t)
{
	unsigned int i;
	unsigned int corners[4];

	corners[0] = 3;
	corners[1] = 0;
	corners[2] = 3;
	corners[3] = 0;
	i = -1;
	while (++i < 16)
		if (t->str[i] == '#')
		{
			corners[0] = (i % 4 < corners[0]) ? i % 4 : corners[0];
			corners[1] = (i % 4 > corners[1]) ? i % 4 : corners[1];
			corners[2] = (i / 4 < corners[2]) ? i / 4 : corners[2];
			corners[3] = (i / 4 > corners[3]) ? i / 4 : corners[3];
		}
	t->width = 1 + corners[1] - corners[0];
	t->height = 1 + corners[3] - corners[2];
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

void	tetprint(t_etris *t)
{
	int i;

	i = 0;
	while (t->str && i < 4)
	{
		write(1, t->str + 4 * i++, 4);
		write(1, "\n", 1);
	}
	printf("w:%d h:%d\n", t->width, t->height);
}
