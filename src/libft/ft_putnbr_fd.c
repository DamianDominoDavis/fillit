/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 17:37:17 by cbrill            #+#    #+#             */
/*   Updated: 2018/04/22 18:18:15 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	out[22];
	int		ncpy;
	int		w;
	int		sign;

	ncpy = n;
	w = 1;
	while ((ncpy /= 10))
		w++;
	sign = n < 0 ? 1 : 0;
	ft_bzero(out, 22);
	if (sign)
		out[0] = '-';
	while (w--)
	{
		*(out + sign + w) = '0' + (sign ? -(n % 10) : (n % 10));
		n /= 10;
	}
	ft_putstr_fd(out, fd);
}
