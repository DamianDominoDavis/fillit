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
	char** pieces = (char**)malloc(sizeof(char**) * (size + 1));
	for (unsigned int i=0; i<=size+1; i++)
		pieces[i] = ft_strnew(20);
	return (pieces);
}

void	unmake_tab(char **pieces)
{
	char *p = *pieces;
	while (p)
		ft_strdel(&p);
	free(pieces);
	pieces = NULL;
}
