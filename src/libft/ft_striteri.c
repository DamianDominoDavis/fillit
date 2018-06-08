/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:14:22 by cbrill            #+#    #+#             */
/*   Updated: 2018/05/03 12:03:45 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	int lim;
	int i;

	if (str && str[0] && f)
	{
		i = -1;
		lim = ft_strlen(str);
		while (++i < lim)
			(*f)(i, &str[i]);
	}
}
