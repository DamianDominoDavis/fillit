/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:51:26 by cbrill            #+#    #+#             */
/*   Updated: 2018/04/24 13:23:19 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *str, char delim)
{
	int		i;

	i = 0;
	while (*str)
	{
		while (*str == delim)
			str++;
		if (*str != '\0')
			i++;
		while (*str && *str != delim)
			str++;
	}
	return (i);
}

char		**ft_strsplit(char const *str, char delim)
{
	char	**out;
	int		oi;
	int		i;
	int		start;

	if (!str || !
		(out = (char**)malloc(sizeof(char*) * (ft_wordcount(str, delim)) + 1)))
		return (NULL);
	oi = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == delim)
			i++;
		start = i;
		while (str[i] && str[i] != delim)
			i++;
		if (i > start)
			out[oi++] = ft_strndup(str + start, i - start);
	}
	out[oi] = NULL;
	return (out);
}
