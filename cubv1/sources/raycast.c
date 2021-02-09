/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:17:25 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/02/09 20:00:20 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_cast_ray(t_all *all)
{
	t_plr	ray = *all->plr; // задаем координаты луча равные координатам игрока

	while (all->map[(int)(ray.y / RECT)][(int)(ray.x / RECT)] != '1' && ray.x <
		   	600 && ray.y < 800) //тут изменил, поправь
	{
		ray.x += cos(ray.a);
		ray.y += sin(ray.a);
//		printf("ray.x: %f ray.y: %f\n", ray.x, ray.y);
	//	mlx_pixel_put(all->win->mlx, all->win->win, ray.x, ray.y, get_trgb(0, 50, 200, 40));
	}
}

void	paint_sky(t_all *all, int x, float i, int color)
{
	float k;

	k = 0;
	while (k < i)
	{
		my_mlx_pixel_put(all, x, k, color);
		k++;
	}
}

void	paint_floor(t_all *all, int x, float i, int color)
{
	while (i < 600)
	{
		my_mlx_pixel_put(all, x, i, color);
		i++;
	}
}

void	ft_cast_rays(t_all *all)
{
	t_plr	ray = *all->plr; // задаем координаты и направление луча равные координатам игрока
	float start = ray.a - PI/6; // начало веера лучей
	float end = ray.a + PI/6;	// край веера лучей
	float c = 0.0;

	float i = fabs(c * cos(start));
	int x = 0;
	int color1 = get_trgb(0, 255, 136, 0);
	int color2 = get_trgb(0, 100, 139, 200);
	int tmp_color = 0;
	float tmp = 0;

	while (start <= end)
	{
		ray.x = all->plr->x; // каждый раз возвращаемся в точку начала
		ray.y = all->plr->y;
		while (all->map[(int)(ray.y / RECT)][(int)(ray.x / RECT)] != '1')
		{
			ray.x += cos(start);
			ray.y += sin(start);
			if (all->map[(int)(ray.y / RECT)][(int)(ray.x / RECT)] == '1')
				break;
			c += 0.6;
			//my_mlx_pixel_put(all, ray.x, ray.y, 0x990099);
		}
		//printf("c(%d) = %f\n", chet++, c); 

		i = c * fabs(cos(start - all->plr->a));	
		paint_sky(all, x, i, get_trgb(0, 8, 232, 222));
		while (i++ <  600 -  c* fabs(cos(start - all->plr->a)))
		{
			//printf("c(%d) = %f\n", chet++, c); 
			if (fabsf(c - tmp) > 10)
			{
				tmp_color = color1;
				color1 = color2;
				color2 = tmp_color;
			}
			my_mlx_pixel_put(all, x, i, color1);
			tmp = c;
		}
		paint_floor(all, x, i, get_trgb(0, 61, 41, 31));
		x+=1;
		c = 0.0;
		start += PI/3 / 800;
	}
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
}
