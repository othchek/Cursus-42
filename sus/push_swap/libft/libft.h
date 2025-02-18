/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:00:17 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/29 17:00:23 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int				ft_isalnum(int c);
long long		ft_atoi(char *str);
void			ft_error(char *str);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_strchr(char *s, int c);
size_t			ft_strlen(char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strrchr(char *s, int c);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strdup(char *s1);
size_t			ft_strlcat(char *dst, char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strtrim(char *s1, char *set);
char			*ft_strmapi(char *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_itoa(int n);
char			**ft_split(char *s, char c);

#endif
