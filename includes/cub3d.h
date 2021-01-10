/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:36:17 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/01/10 17:23:26 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/includes/libftprintf.h"
# include "../libft/get_next_line.h"
# include <fcntl.h>
# include <math.h>

# define RECT 10
# define PI 3.141592 

typedef struct s_win
{
    int width;
    int height;
	void *mlx;
	void *win;
	void *img;
	char *adr;
	  
}               t_win;

typedef struct s_plr
{
	float x;
	float y;
	float a;
}				t_plr;

typedef struct	s_all
{
	t_win *win;
	t_plr *plr;
	char **map;
}				t_all;
/*
    **Color
*/
int		get_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
void ft_error(int error);
/*
    **Inits
*/
void	init_window(t_win *window);
void	init_all(t_all *all);
/*
    **Get map
*/
void	get_lstmap(int fd, t_all *all);
void	get_map(int size, t_list *lstmap, t_all *all);
//int		get_pos_player(char **map, int i, int j);
int		get_pos_player(t_all *all);
/*
    **Draw
*/
void	draw_map(t_all *all);
//void	draw_pix(t_all *all, int rectsize, int i, int j, int color);
void	draw_pix(t_all *all, int rectsize, int x, int y, int color);
void	draw_player(t_all *all, int plrsize, int x, int y, int color);
void	draw_map_rect(t_all *all, int color);
int		key_press(int key, t_all *all);
/*
	**raycast
*/
void	ft_cast_ray(t_all *all);
void	ft_cast_rays(t_all *all);

#endif
