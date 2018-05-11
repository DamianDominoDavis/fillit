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

int	main(int c, char** v)
{
	unsigned int magic = 26;
	char** pieces = make_pieces(magic);
	if (!pieces)
	{
		ft_putendl_fd("ABORT: could not allocate space for pieces.", 2);
		return (0);
	}
	
	if (c==2 && v[1])
		readPatternFile(v[1], pieces);
	else
	{
		ft_putendl_fd("usage: fillit pieces.txt", 2);
		return (0);
	}
	
	if (!pieces)
	{
		ft_putendl_fd("ABORT: invalid pattern file.", 2);
		return (0);
	}
	
	for (magic=0; pieces[magic][0]; magic++) ;
	
	ft_putendl("Accepted these pieces:");
	for (unsigned int i=0; i<magic; i++)
		tetprint(pieces[i]);
	// (void)c;(void)v;

	// char str[17] = "ABCDEFGHIJKLMNOP\0";
	// ft_strshift(str, 4);
	// printf("%s\n", str);

	return (0);
}
