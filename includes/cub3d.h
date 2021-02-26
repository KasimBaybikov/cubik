/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:08:10 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/26 14:20:34 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/mlx/mlx.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>

typedef struct
{
	int w;
	int h;
	void *mlx;
	void *win;
}	t_win;

typedef struct
{
	float x;
	float y;
	float dir_x;
	float dir_y;
	float plane_x;
	float plane_y;
}	t_plr;

typedef struct
{
	int f_r;
	int f_g;
	int f_b;
	int c_r;
	int c_g;
	int c_b;
}	t_clr;

typedef struct
{
	char *no;
	char *so;
	char *we;
	char *ea;
	char *spr;
}	t_tex;

typedef struct
{
	int x;
	int y;
}	t_spr;

typedef struct
{
	void *img;
	char *addr;
	int bpp;
	int line_len;
	int endian;
}	t_img;

typedef struct
{
	char **map;
	t_win *win;
	t_plr *plr;
	t_clr *clr;
	t_tex *tex;
	t_spr *spr;
	t_img *img;
	int map_w;
	int map_h;
}	t_all;

typedef struct
{
	int r;
	int no;
	int so;
	int we;
	int ea;
	int s;
	int f;
	int c;
	int flag;
} 	t_key;


void	error(int error);
void	start(char *map_name, t_all *all);
int		check_map_name(char *name);
void	init_all(t_all *all);
void	parse_file(t_all *all, int fd);
void	parse_map(t_all *all, int fd);
int		valid_line(char *line);
void	my_mlx_pixel_put(t_all *all, int x, int y, int color);

int		is_empty(char *line);
void	get_r(t_all *all, char *line, t_key *key);
void	get_no(t_all *all, char *line, t_key *key);
void	get_so(t_all *all, char *line, t_key *key);
void	get_we(t_all *all, char *line, t_key *key);
void	get_ea(t_all *all, char *line, t_key *key);
void	get_s(t_all *all, char *line, t_key *key);
void	get_f(t_all *all, char *line, t_key *key);
void	get_c(t_all *all, char *line, t_key *key);
int		get_pos_plr(t_all *all);
void	get_sprites(t_all *all, int x, int y, int i);
void	init_key(t_key *key);
int		rgb_make(int t, int r, int g, int b);
void	draw(t_all *all);
#endif
