/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:08:25 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/08 16:32:14 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "get_next_line.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct l_cub 
{
    char **map;
    char **elements;
    int map_height;

} t_cub;

int     ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_error(char *s);
char	**read_map(t_cub *cub, char *av);
void	map_height(t_cub *cub, char *name);
void	ft_putstr_fd(char *s, int fd);
void	checkmapextension(char *filename);
char	**devide_map(t_cub *oth);
void    checkmap(t_cub *oth, char c);

#endif
