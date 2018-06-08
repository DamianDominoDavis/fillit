/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:34:45 by cbrill            #+#    #+#             */
/*   Updated: 2018/04/21 12:37:14 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	char	*tmp;

	tmp = dst + ft_strlen(dst);
	while (*src)
		*tmp++ = *src++;
	*tmp = '\0';
	return (dst);
}
