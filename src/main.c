/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:46:04 by cbrill            #+#    #+#             */
/*   Updated: 2018/05/10 20:49:03 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

int		main(int c, char **v)
{
	unsigned int	magic;
	char			**pieces;
	unsigned int	i;

	magic = 26;
	pieces = make_pieces(magic);
	if (!pieces)
	{
		ft_putendl_fd("ABORT: could not allocate space for pieces.", 2);
		return (0);
	}
	if (c == 2 && v[1])
		read_pattern_file(v[1], pieces);
	else
	{
		ft_putendl_fd("usage: fillit pieces.txt", 2);
		return (0);
	}
	return (0);
}
