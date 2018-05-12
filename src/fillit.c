/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:34:48 by cbrill            #+#    #+#             */
/*   Updated: 2018/05/10 20:22:55 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**make_pieces(unsigned int size)
{
	char				**pieces;
	unsigned int		i;

	pieces = (char**)malloc(sizeof(char**) * (size + 1));
	i = 0;
	while (i < size)
		pieces[i++] = ft_strnew(20);
	pieces[i] = NULL;
	return (pieces);
}

char	**make_board(unsigned int size)
{
	char				**board;
	unsigned int		i;

	board = (char**)malloc(sizeof(char**) * (size + 1));
	i = 0;
	while (i < size)
	{
		board[i] = ft_strnew(size);
		ft_strfill(board[i++], '.');
	}
	board[i] = NULL;
	return (board);
}

void	unmake_tab(char **pieces)
{
	char	*p;

	p = *pieces;
	while (p)
		ft_strdel(&p);
	free(pieces);
	pieces = NULL;
}

void	solve(char **pieces, char **board)
{
	(void)pieces;
	(void)board;
}
