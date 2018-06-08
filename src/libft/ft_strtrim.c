/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:18:31 by cbrill            #+#    #+#             */
/*   Updated: 2018/04/21 16:40:59 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	unsigned int	l;
	unsigned int	r;

	if (!str)
		return (NULL);
	l = 0;
	while (str[l] == ' ' || str[l] == '\n' || str[l] == '\t')
		l++;
	if (str[l] == '\0')
		return (ft_strnew(0));
	r = ft_strlen(str) - 1;
	while (str[r] == ' ' || str[r] == '\n' || str[r] == '\t')
		r--;
	return (ft_strsub(str, l, r - l + 1));
}
