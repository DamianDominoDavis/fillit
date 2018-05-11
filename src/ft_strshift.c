/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:20:33 by cbrill            #+#    #+#             */
/*   Updated: 2018/05/10 17:20:47 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_strshift(char *str, unsigned int n)
{
	char *buf;
	int len;

	if (!str)
		return ;
	len = ft_strlen(str);
	if ((n %= len) == 0 || !(buf = ft_strnew(len)))
		return ;
	ft_memcpy(buf, str + n, len - n);
	ft_memcpy(buf + len - n, str, n);
	ft_memcpy(str, buf, len);
	ft_strdel(&buf);
}
