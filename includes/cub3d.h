/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:08:10 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/19 19:20:33 by rvernon          ###   ########.fr       */
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
	void *img;
	char *addr;
	int bpp;
	int endian;
	int line_length;
}	t_win;

typedef struct
{
	float x;
	float y;
	float a;
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
	char **map;
	t_win *win;
	t_plr *plr;
	t_clr *clr;
	t_tex *tex;
}	t_all;

void	error(int error);
void	start(char *s);
int		check_map_name(char *name);
void	init_all(t_all *all);
void	parse_file(t_all *all, int fd);

void	get_r(t_all *all, char *line);
void	get_no(t_all *all, char *line);
void	get_so(t_all *all, char *line);
void	get_we(t_all *all, char *line);
void	get_ea(t_all *all, char *line);
void	get_s(t_all *all, char *line);
void	get_f(t_all *all, char *line);
#endif
