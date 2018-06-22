/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:51:01 by cbrill            #+#    #+#             */
/*   Updated: 2018/06/17 17:47:35 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		nope(char *msg, int fd, int rvalue)
{
	if (msg)
		ft_putendl_fd(msg, fd);
	return (rvalue);
}

int		main(int c, char **v)
{
	t_etris	*pieces[27];
	int		i;
	char	**board;

	if (c != 2)
		return (nope("usage: fillit patterns.txt", 1, 0));
	i = -1;
	while (++i < 27)
	{
		if (!(pieces[i] = (t_etris*)ft_memalloc(sizeof(t_etris))))
			return (nope("error", 1, 0));
		pieces[i]->str = NULL;
	}
	if ((readpieces(open(v[1], O_RDONLY), pieces)) == 0)
		return (nope("error", 1, 0));
	board = solve(pieces);
	printboard(board);
	return (0);
}
