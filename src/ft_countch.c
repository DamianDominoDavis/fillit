/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 19:32:07 by cbrill            #+#    #+#             */
/*   Updated: 2018/05/07 15:15:54 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_countch(const char* str, const unsigned char ch)
{
	char *s = (char*)str;
	int i = 0;
	while (*s)
		if (*s++ == ch)
			i++;
	return (i);
}
