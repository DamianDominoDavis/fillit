/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   streamlined.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:51:01 by cbrill            #+#    #+#             */
/*   Updated: 2018/05/31 18:43:48 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		nope(char *msg, int fd, int rvalue)
{
	write(fd, msg, strlen(msg));
	write(fd, "\n", 1);
	return (rvalue);
}

int		main(int c, char **v)
{
	int count;
	char pieces[26];

	if (c != 2)
		return nope("usage: fillit patterns.txt", 1, 1);
	if ((count = readpieces(open(v[1], O_RDONLY), pieces)) == 0)
		return nope("could not read pieces.", 2, 2);
	
 	return (0);
}
