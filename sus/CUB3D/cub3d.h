/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:08:25 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/12 17:01:41 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct l_cub 
{
	char	**allmap;
	char	**map;
	int		map_height;
	char	*f;
	char	*c;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_cub;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_error(char *s);
char	**read_map(t_cub *cub, char *av);
void	map_height(t_cub *cub, char *name);
void	ft_putstr_fd(char *s, int fd);
void	parse_rgb(t_cub *cub);
int		parse_elmnt_value(char *str);
void	parse_xpmfiles(t_cub *cub);
int		check_which_elmnt(char **str, t_cub *cub);
void	checkmapextension(char *filename);
char	**devide_map(t_cub *cub);
void	checkmap(t_cub *cub);
int		ft_strfound(char* haystack, char* needle);
void	store_elements(t_cub *cub);
void	store_it(t_cub *cub);
int		ft_strcmp(char *s1, char *s2);
char    **ft_split2(char *s, char *c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isdigit(int c);
int		is_valid_key_value(char *key, char *value, char k);

#endif
