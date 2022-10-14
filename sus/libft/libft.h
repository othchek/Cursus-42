#include <unistd.h>
#include <stdio.h>

#ifndef LIBFT_H
#define LIBFT_H

int	ft_isalnum(int c);
int ft_atoi(const char *str);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_tolower(int c);
int	ft_toupper(int c);
char    *ft_strrchr(const char *s, int c);
void *ft_memset(void *b, int c, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif

