/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:05:21 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/02/09 20:43:06 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_map_rect(t_all *all, int color)
{
	int y;
	int x;

	y = -1;
	x = -1;
	while (all->map[++y])
	{
		while (all->map[y][++x])
		{
			if (all->map[y][x] == '1')
				draw_pix(all, RECT, x, y, color);
		}
		x = -1;
	}
}

void	draw_player(t_all *all, int plrsize, int x, int y, int color)
{
	int i;
	int j;

	i = -1;
	j = -1;
	all->plr->x = x;
	all->plr->y = y;
	while (++i < plrsize)
	{
		while (++j < plrsize)
		{		
			mlx_pixel_put(all->win->mlx, all->win->win, (all->plr->x) + i, (all->plr->y) + j, color);
		}
		j = -1;
	}
	//printf("x: %f y: %f\n", all->plr->x, all->plr->y);
}

void	draw_pix(t_all *all, int rectsize, int x, int y, int color)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < rectsize)
	{
		while (++j < rectsize)
				my_mlx_pixel_put(all, (x*rectsize) + i, (y*rectsize) + j, color);
		j = -1;
	}
}

void	draw_map(t_all *all)
{
	int i;
	int j;

	i = -1;
	j = -1;
	all->win->mlx = mlx_init();
	all->win->win = mlx_new_window(all->win->mlx, 800, 600, "Cub3D");
	draw_map_rect(all, get_trgb(0, 255, 150, 200));
	get_pos_player(all);
	//draw_player(all, RECT, all->plr->x, all->plr->y, get_trgb(0, 10, 20, 200));
	//ft_cast_rays(all);
	//mlx_key_hook(all->win->win, key_press, all);
	mlx_hook(all->win->win, 2, (1L << 0), key_press, all);
	mlx_loop(all->win->mlx);
}
