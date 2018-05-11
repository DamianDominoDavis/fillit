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

char	*ft_stripch(const char* str, unsigned int n, const unsigned char ch)
{
	char *out;
	out = ft_strnew(ft_strlen(str) - ft_countch(str, ch));
	char *o = out;
	char *s = (char*)str;
	while (n--)
		if (*s == ch)
			s++;
		else
			*o++ = *s++;
	*o = '\0';
	return (out);
}
