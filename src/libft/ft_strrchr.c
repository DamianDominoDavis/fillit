/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:34:15 by cbrill            #+#    #+#             */
/*   Updated: 2018/04/21 17:01:34 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*out;

	out = NULL;
	if (*str == (char)c)
		out = (char*)str;
	while (*str++)
		if (*str == (char)c)
			out = (char*)str;
	return (out);
}
