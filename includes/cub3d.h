/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:08:10 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/04 10:48:44 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/mlx/mlx.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>
# define rot_speed 0.07
# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define SHIFT_KEY 257

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
	float move_speed;
	int tex_num;
	float wall_x;
	int tex_x;
	float step;
	float tex_pos;
	int tex_y;
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
	float x;
	float y;
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
	int shift;
}	t_hook;

typedef struct
{
	void *img_data;
	void *img_ptr;
	int *data;
	int line_len;
	int endian;
	int width;
	int height;
	int bpp;
}	t_textures;

typedef struct
{
	int num_sprites;
	int *spr_order;
	float *spr_dist;
	float spr_x;
	float spr_y;
	float inv_det;
	float transform_x;
	float transform_y;
	int spr_screen_x;
	int spr_h;
	int dr_start_y;
	int dr_end_y;
	int spr_w;
	int dr_start_x;
	int dr_end_x;
	int stripe;
	int tex_x;
	int tex_y;
	int d;
	int y;
	int color;
}	t_sprite;

typedef struct
{
	char **map;
	t_win *win;
	t_plr *plr;
	t_clr *clr;
	t_tex *tex;
	t_img *img;
	t_hook *hook;
	int map_w;
	int map_h;
	t_textures *north;
	t_textures *south;
	t_textures *west;
	t_textures *east;
	t_textures *sprite;
	t_sprite *sprr;
	t_spr *spr;
	float *z_buf;
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


void	error(int error, t_all *all);
void	start(char *map_name, t_all *all);
int		check_map_name(char *name, t_all *all);
void	init_all(t_all *all);
void	parse_file(t_all *all, int fd);
void	parse_map(t_all *all, int fd);
int		valid_line(char *line);
void	pixel_put(t_all *all, int x, int y, int color);

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
void	sprite_casting(t_all *all, t_sprite *sprr);

int		key_down(int key, t_all *all);
int		key_up(int key, t_all *all);
void	floor_paint(t_all *all);
void	ceiling_paint(t_all *all);
void	new_keys(t_all *all, t_plr *plr);

void	move_w(t_all *all, t_plr *plr);
void	move_s(t_all *all, t_plr *plr);
void	move_a(t_all *all, t_plr *plr);
void	free_all(t_all *all);
#endif
