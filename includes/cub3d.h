/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:08:10 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/17 15:21:51 by rvernon          ###   ########.fr       */
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
	int floor_clr;
	int ceilling_clr;
}	t_clr;

typedef struct
{
	char *n;
	char *s;
	char *w;
	char *e;
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
void parse_file(t_all *all, int fd);

#endif
