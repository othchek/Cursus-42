/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:38:31 by otchekai          #+#    #+#             */
/*   Updated: 2023/02/22 16:10:50 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct l_ping
{
	char	**map;
	char	**pam;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*img_ptr2;
	void	*background;
	void	*wall;
	void	*exitgate;
	void	*collectible;
	void	*frisk;
	int		map_height;
	int		var;
	int		map_width;
	int		player;
	int		collectibles;
	int		exits;
	int		player_y;
	int		player_x;
}				t_ping;

char	**read_map(t_ping *so_long, char *av);
void	copy(t_ping *oth);
void	check_walls(t_ping *oth);
void	what_to_print(t_ping *oth, int j, int i);
void	ft_error(char *s);
void	map_height(t_ping *so_long, char *name);
void	width_check(t_ping *oth);
void	checkmapextension(char *filename);
void	check_content(t_ping *oth);
void	check_content2(t_ping *oth);
void	butts_ifs_and_maybes(t_ping *oth);
void	playerposition(t_ping *oth);
int		floodfill(char **ptr, int x, int y);
void	xpmlikexpf(t_ping *oth);
int		key(int keycode, t_ping *oth);
void	destroyleaks(t_ping *oth);
void	check(t_ping *oth);
void	printmove(t_ping *oth, int keycode);
void	printmove2(t_ping *oth, int keycode);
void	what_to_print(t_ping *oth, int j, int i);
void	what_to_print2(t_ping *oth, int j, int i);

#endif