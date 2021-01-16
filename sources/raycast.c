/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:17:25 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/01/16 17:14:14 by kasimbayb        ###   ########.fr       */
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
		mlx_pixel_put(all->win->mlx, all->win->win, ray.x, ray.y, get_trgb(0, 50, 200, 40));
	}
}

void	ft_cast_rays(t_all *all)
{
	t_plr	ray = *all->plr; // задаем координаты и направление луча равные координатам игрока
	float start = ray.a - PI/6; // начало веера лучей
	float end = ray.a + PI/6;	// край веера лучей
	float c = 0.0;

	float i = -1;
	int x = -1;
	int chet = 1;
	while (start <= end)
	{
		ray.x = all->plr->x; // каждый раз возвращаемся в точку начала
		ray.y = all->plr->y;
		while (all->map[(int)(ray.y / RECT)][(int)(ray.x / RECT)] != '1' && c < 40)
		{
			ray.x += cos(start);
			ray.y += sin(start);
			if (all->map[(int)(ray.y / RECT)][(int)(ray.x / RECT)] == '1')
				break;
			c += 0.1;
			//mlx_pixel_put(all->win->mlx, all->win->win, ray.x, ray.y, 0x990099);
		}
		printf("c(%d) = %f\n", chet++, c); 
		
		while (++i < 200 - c * 5)
		{
			//printf("c(%d) = %f\n", chet++, c); 
				mlx_pixel_put(all->win->mlx, all->win->win, x, c*1.5 + i + 350, get_trgb(0, 139, 0, 139));
				mlx_pixel_put(all->win->mlx, all->win->win, x + 1, c*1.5 + i + 350, get_trgb(0, 139, 0, 139));
				mlx_pixel_put(all->win->mlx, all->win->win, x + 2, c*1.5 + i + 350, get_trgb(0, 139, 0, 139));
		}
		x+=3;
		i = -1;
		c = 0.0;
		start += PI/3 / 300;
	}
}
