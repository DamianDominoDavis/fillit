/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:38:39 by cbrill            #+#    #+#             */
/*   Updated: 2018/04/21 18:18:40 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*out;
	int		ncpy;
	int		w;
	int		sign;

	ncpy = n;
	w = 1;
	while ((ncpy /= 10))
		w++;
	sign = n < 0 ? 1 : 0;
	out = ft_strnew(w + sign);
	if (out == NULL)
		return (NULL);
	if (sign)
		out[0] = '-';
	while (w--)
	{
		out[sign + w] = '0' + (sign ? -(n % 10) : (n % 10));
		n /= 10;
	}
	return (out);
}
