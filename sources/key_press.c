/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:21:27 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/01/20 11:26:16 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		key_press(int key, t_all *all)
{
//	printf("key: %d\n", key);
	all->win->img = mlx_new_image(all->win->mlx, 800, 600);
	all->win->addr = mlx_get_data_addr(all->win->img, &all->win->bits_per_pixel, &all->win->line_length, &all->win->endian);
	if (key == 13) //w
	{
		all->plr->x += cos(all->plr->a)*3;
		all->plr->y += sin(all->plr->a)*3;
	}
	else if (key == 1) //s
	{
		all->plr->x -= cos(all->plr->a)*3;
		all->plr->y -= sin(all->plr->a)*3;
		//all->plr->y += 5;
	}
	else if (key == 0) //a
	{
		all->plr->x -= cos(all->plr->a + PI/2)*3;
		all->plr->y -= sin(all->plr->a + PI/2)*3;
		//all->plr->y += 5;
	}
	else if (key == 2) //d
	{
		all->plr->x -= cos(all->plr->a - PI/2)*3;
		all->plr->y -= sin(all->plr->a - PI/2)*3;
	}
	else if (key == 123) // <-
	{
		if (all->plr->a < 0)
			all->plr->a += 2*PI;
		all->plr->a -= PI/50;
	}
	else if (key == 124) // ->
	{
		if (all->plr->a > 2*PI)
			all->plr->a -= 2*PI;
		all->plr->a += PI/50;
	}
	if (key == 53)
		exit(0);
	draw_map_rect(all, get_trgb(0, 255, 150, 200));
//	draw_player(all, RECT, all->plr->x, all->plr->y, get_trgb(0, 10, 20, 200));
//	ft_cast_ray(all);
	ft_cast_rays(all);
	//mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	//free(all->win->img);
	//free(all->win.addr);
	return (0);
}
