/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:05:21 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/01/10 15:20:04 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

void	ft_cast_ray(t_all *all)
{
	t_plr	ray = *all->plr; // задаем координаты луча равные координатам игрока

	while (all->map[(int)(ray.y / RECT)][(int)(ray.x / RECT)] != '1' && ray.x < 600 && ray.y < 800) //тут изменил, поправь
	{
		ray.x += cos(ray.a);
		ray.y += sin(ray.a);
		printf("ray.x: %f ray.y: %f\n", ray.x, ray.y);
		mlx_pixel_put(all->win->mlx, all->win->win, ray.x, ray.y, get_trgb(0, 50, 200, 40));
	}
}

void	ft_cast_rays(t_all *all)
{
	t_plr	ray = *all->plr; // задаем координаты и направление луча равные координатам игрока
	float start = ray.a - PI/4; // начало веера лучей
	float end = ray.a + PI/4;	// край веера лучей
	float c = 0.0;

	while (start <= end)
	{
		ray.x = all->plr->x; // каждый раз возвращаемся в точку начала
		ray.y = all->plr->y;
		while (all->map[(int)(ray.y / RECT)][(int)(ray.x / RECT)] != '1' && c < 20)
		{
			ray.x += cos(start);
			ray.y += sin(start);
			c += 0.1;
			mlx_pixel_put(all->win->mlx, all->win->win, ray.x, ray.y, 0x990099);
		}
		c = 0.0;
		start += PI/2 / 500;
	}
}

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

int		key_press(int key, t_all *all)
{
	mlx_clear_window(all->win->mlx, all->win->win);
	//printf("%d", key);
	if (key == 13) //w
		all->plr->y -= 5;
	else if (key == 1) //s
		all->plr->y += 5;
	else if (key == 0) //a
		all->plr->x -= 5;
	else if (key == 2) //d
		all->plr->x += 5;
	else if (key == 123) // <-
	{
		if (all->plr->a < 0)
			all->plr->a += 2*PI;
		all->plr->a -= PI/10;
	}
	else if (key == 124) // <-
	{
		if (all->plr->a > 2*PI)
			all->plr->a -= 2*PI;
		all->plr->a += PI/10;
	}
	if (key == 53)
		exit(0);
	//printf("%f\n", all->plr->a);
	draw_map_rect(all, get_trgb(0, 255, 150, 200));
	draw_player(all, RECT, all->plr->x, all->plr->y, get_trgb(0, 10, 20, 200));
	ft_cast_rays(all);
	return (0);
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
				mlx_pixel_put(all->win->mlx, all->win->win, (x*rectsize) + i, (y*rectsize) + j, color);
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
	draw_player(all, RECT, all->plr->x, all->plr->y, get_trgb(0, 10, 20, 200));
	ft_cast_rays(all);
	mlx_key_hook(all->win->win, key_press, all);
	mlx_loop(all->win->mlx);
}
