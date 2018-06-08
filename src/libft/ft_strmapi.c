/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:10:25 by cbrill            #+#    #+#             */
/*   Updated: 2018/04/24 14:44:29 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	i;

	if (!str || !(out = ft_strnew(ft_strlen(str))))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		out[i] = f(i, str[i]);
		i++;
	}
	return (out);
}
