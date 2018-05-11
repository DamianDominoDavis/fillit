/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:04:39 by cbrill            #+#    #+#             */
/*   Updated: 2018/05/04 18:43:28 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// void				*ft_memset(void *p, int c, size_t len);
// void				ft_bzero(void *str, size_t n);
// void				*ft_memcpy(void *dst, const void *src, size_t n);
// void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
// void				*ft_memmove(void *dst, const void *src, size_t len);
// void				*ft_memchr(const void *str, int c, size_t n);
// int					ft_memcmp(const void *s1, const void *s2, int n);
size_t				ft_strlen(const char *str);
// char				*ft_strdup(const char *str);
// char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
// char				*ft_strcat(char *dst, const char *src);
// char				*ft_strncat(char *dst, const char *src, size_t n);
// size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
// char				*ft_strchr(const char *str, int c);
// char				*ft_strrchr(const char *str, int c);
// char				*ft_strstr(const char *haystack, const char *needle);
// char				*ft_strnstr(const char *haystack, const char *needle,
// 						size_t len);
// int					ft_strcmp(const char *s1, const char *s2);
// int					ft_strncmp(const char *s1, const char *s2, size_t n);
// int					ft_atoi(const char *str);
// int					ft_isalpha(int c);
// int					ft_isdigit(int c);
// int					ft_isalnum(int c);
// int					ft_isascii(int c);
// int					ft_isprint(int c);
// int					ft_isupper(int c);
// int					ft_islower(int c);

void				*ft_memalloc(size_t size);
// void				ft_memdel(void **p);
char				*ft_strnew(size_t size);
// void				ft_strdel(char **str);
// void				ft_strclr(char *str);
// void				ft_striter(char *str, void (*f)(char*));
// void				ft_striteri(char *str, void (*f)(unsigned int, char*));
// char				*ft_strmap(char const *str, char (*f)(char));
// char				*ft_strmapi(char const *str, char (*f)(unsigned int, char));
// int					ft_strequ(char const *s1, char const *s2);
// int					ft_strnequ(char const *s1, char const *s2, size_t n);
// char				*ft_strsub(char const *str, unsigned int start, size_t len);
// char				*ft_strjoin(char const *s1, char const *s2);
// char				*ft_strtrim(char const *str);
// char				**ft_strsplit(char const *str, char delim);
// char				*ft_itoa(int n);
// void				ft_putchar(char c);
// void				ft_putstr(char *str);
// void				ft_putendl(char *c);
// void				ft_putnbr(int n);
// void				ft_putchar_fd(char c, int fd);
// void				ft_putstr_fd(char *str, int fd);
// void				ft_putendl_fd(char *str, int fd);
// void				ft_putnbr_fd(int n, int fd);

// t_list				*ft_lstnew(void const *content, size_t content_size);
// void				ft_lstadd(t_list **alst, t_list *new);
// void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
// void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
// void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
// t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

// int					ft_isspace(int c);
char				*ft_strndup(const char *str, size_t n);
// int					ft_stroverlap(const char *s1, const char *s2);
// int					ft_tolower(int c);
// int					ft_toupper(int c);

#endif