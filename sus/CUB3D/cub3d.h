/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:08:25 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/18 17:25:28 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "mlx.h"

# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef tile_size
# define tile_size 32
#endif

typedef struct l_cub {
	struct s_data	*content;
	char			**allmap;
	char			**map;
	char			**defmap;
	void			*mlx_ptr;
	void			*win_ptr;
	int				map_height;
	int				map_width;
	int				ones_length;
	char			*f;
	char			*c;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
}	t_cub;

typedef struct	s_data {
	t_cub	*data;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_error(char *s);
char	**read_map(t_cub *cub, char *av);
void	map_height(t_cub *cub, char *name);
void	ones_length(t_cub *cub);
void	width_check(t_cub *cub);
void	process_rgb_line(char *str, int *key, int *delimiter, int *count);
void	ft_putstr_fd(char *s, int fd);
void	parse_rgb(t_cub *cub);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	loop_zeros(t_cub *cub, t_data *img);
void	draw_square(int x, int y, t_data *img, int color);
int		key(int keycode, t_cub *oth);
void	parse_xpmfiles(t_cub *cub);
void	checkmapextension(char *filename);
char	**devide_map(t_cub *cub);
char	**defmap(t_cub *cub);
void	checkmap(t_cub *cub);
void	parse_map(t_cub *cub);
void	parse_zeros(t_cub *cub);
void	parse_empty_line(t_cub *cub);
void	parse_player(t_cub *cub);
int		player_valid(t_cub *cub, int i, int j);
int		ft_strfound(char *haystack, char *needle);
void	store_it(t_cub *cub);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split2(char *s, char *c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isdigit(int c);

#endif
