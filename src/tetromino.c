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

void	readPatternFile(const char *path, char **save)
{
	int fd;
	char candidate[21];
	char *s;
	char nl[1];

	candidate[20] = '\0';
	if (!path || !save)
		return ;
	s = *save;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("readPatternFile: could not read from file.", 1);
		return ;
	}
	while (save && read(fd, candidate, 20) == 20)
		if (isPattern(candidate))
		{
			ft_strncpy(s, ft_stripnl(candidate), ft_strlen(candidate));
			tetprint(s); //<-- THIS WORKS, but main's call doesn't...
			s++;
			if (read(fd, nl, 1) == 0)
				break;
			else if (nl[0] != '\n')
			{
				ft_putendl_fd("readPatternFile: pattern separator must be a single newline character.", 1);
				unmake_tab(save);
			}
		}
		else
		{
			ft_putstr_fd("readPatternFile: invalid pattern, ", 1);
			ft_putendl_fd(candidate, 1);
			unmake_tab(save);
		}
	if (!save)
		ft_putendl_fd("readPattternFile: did not exit sucessfully.", 1);
}

int	isPattern(char* pattern)
{
	if (!pattern || strlen(pattern) != 20
		|| pattern[4] != '\n'
		|| pattern[4] != pattern[9]
		|| pattern[9] != pattern[14]
		)
	{
		ft_putendl_fd("isPattern: argstest fail", 1);
		return 0;
	}
	int x = 0;
	int n = 0;
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
		ft_putstr_fd("isPattern: ntest fail, ", 1);
		ft_putendl_fd(ft_itoa(n), 1);
		return 0;
	}
	return (1);
}

void	tetprint(char* tet)
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
