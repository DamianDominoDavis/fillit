/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:46:00 by cbrill            #+#    #+#             */
/*   Updated: 2018/05/10 20:49:09 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	read_pattern_file(const char *path, char **save)
{
	int		fd;
	char	candidate[21];
	char	*s;

	candidate[20] = '\0';
	if (!path || !save)
		return ;
	s = *save;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("read_pattern_file: could not read from file.", 1);
		return ;
	}
	while (save && read(fd, candidate, 20) == 20)
		if (is_pattern(candidate))
		{
			ft_strncpy(s++, ft_stripnl(candidate), ft_strlen(candidate));
			if (read(fd, candidate, 1) == 0)
				break ;
			else if (candidate[0] != '\n')
			{
				ft_putendl_fd("read_pattern_file: pattern separator must be a single newline character.", 1);
				unmake_tab(save);
			}
		}
		else
		{
			ft_putstr_fd("read_pattern_file: invalid pattern, ", 1);
			ft_putendl_fd(candidate, 1);
			unmake_tab(save);
		}
	if (!save)
		ft_putendl_fd("readPattternFile: did not exit sucessfully.", 1);
	solve(save);
}

int		is_pattern(char *pattern)
{
	int x;
	int n;

	if (!pattern || strlen(pattern) != 20
		|| pattern[4] != '\n'
		|| pattern[4] != pattern[9]
		|| pattern[9] != pattern[14])
	{
		ft_putendl_fd("is_pattern: argstest fail", 1);
		return (0);
	}
	x = 0;
	n = 0;
	while (x <= 20)
	{
		if (pattern[x] == '#')
		{
			if (x < 20 && pattern[x] == pattern[x + 1])
				n++;
			if (x > 0 && pattern[x] == pattern[x - 1])
				n++;
			if (x + 5 <= 20 && pattern[x] == pattern[x + 5])
				n++;
			if (x - 5 >= 0 && pattern[x] == pattern[x - 5])
				n++;
		}
		else if (pattern[x] != '.' && pattern[x] != '\n' && pattern[x] != '\0')
			return (0);
		x++;
	}
	if (n != 6 && n != 8)
	{
		ft_putstr_fd("is_pattern: ntest fail, ", 1);
		ft_putendl_fd(ft_itoa(n), 1);
		return (0);
	}
	return (1);
}

void	tetprint(char *tet)
{
	int i;

	if (!tet)
		return ;
	i = 0;
	while (i < 4)
	{
		write(1, tet + 4 * i++, 4);
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

void	revolve(char *p)
{
	char t;
	int i;

	while (p[0] != '#' && p[1] != '#' && p[2] != '#' && p[3] != '#')
		ft_strshift(p, 4);
	while (p[0] != '#' && p[4] != '#' && p[8] != '#' && p[12] != '#')
	{
		i = 0;
		while (i < 4)
		{
			t = p[4 * i];
			p[4 * i] = p[4 * i + 3];
			p[4 * i + 3] = t;
		}
	}
}
