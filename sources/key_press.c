/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:21:27 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/01/10 17:22:01 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	draw_map_rect(all, get_trgb(0, 255, 150, 200));
	draw_player(all, RECT, all->plr->x, all->plr->y, get_trgb(0, 10, 20, 200));
	ft_cast_rays(all);
	return (0);
}
