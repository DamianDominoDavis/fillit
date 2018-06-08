/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:38:34 by cbrill            #+#    #+#             */
/*   Updated: 2018/04/19 12:53:22 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*found;
	int				clen;
	unsigned char	*s;

	found = ft_memchr(src, (unsigned char)c, n);
	clen = found - (unsigned char*)src + 1;
	s = (unsigned char*)src;
	if (found)
	{
		dst = ft_memcpy(dst, src, clen);
		return (dst + clen);
	}
	else
		dst = ft_memcpy(dst, src, n);
	return (NULL);
}
