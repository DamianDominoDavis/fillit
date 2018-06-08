/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:33:03 by cbrill            #+#    #+#             */
/*   Updated: 2018/04/21 17:04:03 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*h;
	const char	*n;

	if (*haystack == '\0' && *needle == '\0')
		return ((char*)haystack);
	while (*haystack)
	{
		h = haystack;
		n = needle;
		while (*n && *haystack && *n == *haystack)
		{
			n++;
			haystack++;
		}
		if (!*n)
			return ((char*)h);
		haystack = h + 1;
	}
	return (NULL);
}
