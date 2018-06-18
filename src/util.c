/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 16:00:32 by cbrill            #+#    #+#             */
/*   Updated: 2018/06/17 17:47:45 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_countch(const char *str, const unsigned char ch)
{
	char	*s;
	int		i;

	s = (char*)str;
	i = 0;
	while (*s)
		if (*s++ == ch)
			i++;
	return (i);
}

char	*ft_stripch(const char *str, unsigned int n, const unsigned char ch)
{
	char	*out;
	char	*o;
	char	*s;

	if (!str)
		return (NULL);
	if (n == 0 || ft_countch(str, ch) == 0)
		return (ft_strdup(str));
	s = (char*)str;
	out = ft_strnew(ft_strlen(str) - ft_countch(str, ch));
	o = out;
	if (!o)
		return (NULL);
	while (n--)
		if (*s == ch)
			s++;
		else
			*o++ = *s++;
	*o = '\0';
	return (out);
}

char	*ft_stripnl(const char *str)
{
	return (ft_stripch(str, ft_strlen(str), '\n'));
}

void	ft_strrevolve(char *str, unsigned int wide, unsigned int tall)
{
	unsigned int	row;
	unsigned int	w;
	char			tmp;

	row = -1;
	while (++row < tall)
	{
		tmp = str[row * wide];
		w = -1;
		while (++w < wide - 1)
			str[row * wide + w] = str[row * wide + w + 1];
		str[row * wide + wide - 1] = tmp;
	}
}

void	ft_strshift(char *str, unsigned int n)
{
	char	*buf;
	int		len;

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
