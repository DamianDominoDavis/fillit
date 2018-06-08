/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 13:31:05 by cbrill            #+#    #+#             */
/*   Updated: 2018/04/21 16:59:12 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	int		l1;
	int		l2;

	if (!s1 && !s2)
		return (ft_strnew(0));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	out = ft_strnew(l1 + l2 + 1);
	if (!out)
		return (NULL);
	ft_strncpy(out, s1, l1);
	ft_strncat(out + l1, s2, l2);
	return (out);
}
