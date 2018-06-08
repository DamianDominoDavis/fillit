/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:06:39 by cbrill            #+#    #+#             */
/*   Updated: 2018/04/24 14:44:20 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	char				*out;
	unsigned int		i;

	if (!str || !(out = ft_strnew(ft_strlen(str))))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		out[i] = f(str[i]);
		i++;
	}
	return (out);
}
