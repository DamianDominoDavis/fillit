/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stripch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 19:31:46 by cbrill            #+#    #+#             */
/*   Updated: 2018/05/10 16:04:56 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*ft_stripch(const char *str, unsigned int n, const unsigned char ch)
{
	char	*out;
	char	*o;
	char	*s;

	if (!str)
		return (NULL);
	if (n == 0 || ft_countch(str, ch) == 0)
		return (ft_strdup(str));
	s = (char*)str;
	out = ft_strnew(ft_strlen(str) - ft_countch(str, ch));
	o = out;
	if (!o)
		return (NULL);
	while (n--)
		if (*s == ch)
			s++;
		else
			*o++ = *s++;
	*o = '\0';
	return (out);
}
