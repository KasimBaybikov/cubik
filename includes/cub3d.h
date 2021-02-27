/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:08:10 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/27 20:00:06 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/mlx/mlx.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>
# define move_speed 0.05
# define rot_speed 0.05
# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define LEFT_KEY 123
# define RIGHT_KEY 124

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
}	t_vec;

typedef struct
{
	float x;
	float y;
	float dir_x;
	float dir_y;
	float plane_x;
	float plane_y;
	float camera_x;
	float ray_dir_x;
	float ray_dir_y;
	float side_dist_x;
	float delta_dist_x;
	float delta_dist_y;
	float side_dist_y;
	float perp_wall_dist;
	int line_height;
	int draw_start;
	int draw_end;
	int step_x;
	int step_y;
	int hit;
	int side;
	int map_x;
	int map_y;
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
	int esc;
	int w;
	int a;
	int s;
	int d;
	int left;
	int right;
}	t_hook;

typedef struct
{
	char **map;
	t_win *win;
	t_plr *plr;
	t_clr *clr;
	t_tex *tex;
	t_spr *spr;
	t_img *img;
	t_hook *hook;
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
int		calculate(t_all *all);

int		key_down(int key, t_all *all);
int		key_up(int key, t_all *all);
void	floor_paint(t_all *all);
void	ceiling_paint(t_all *all);
void	new_keys(t_all *all, t_plr *plr);

void	move_w(t_all *all, t_plr *plr);
void	move_s(t_all *all, t_plr *plr);
void	move_a(t_all *all, t_plr *plr);
#endif
