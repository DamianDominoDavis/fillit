/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:32:44 by cbrill            #+#    #+#             */
/*   Updated: 2018/04/21 12:34:02 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*buffer;
	char	*b;

	buffer = (char*)malloc(size);
	if (buffer == NULL)
		return (NULL);
	b = buffer;
	while (size--)
		*b++ = 0;
	return (buffer);
}
