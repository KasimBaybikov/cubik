/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:48:46 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/27 20:00:04 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_w(t_all *all, t_plr *plr)
{
	if (all->map[(int)(all->plr->x + plr->dir_x * move_speed)][(int)(all->plr->y)] == '0')
		all->plr->x += plr->dir_x * move_speed;
	if (all->map[(int)(all->plr->x)][(int)(all->plr->y + plr->dir_y * move_speed)] == '0')
		all->plr->y += plr->dir_y * move_speed;
}

void	move_s(t_all *all, t_plr *plr)
{
	if (all->map[(int)(all->plr->x - plr->dir_x * move_speed)][(int)(all->plr->y)] == '0')
		all->plr->x -= plr->dir_x * move_speed;
	if (all->map[(int)(all->plr->x)][(int)(all->plr->y - plr->dir_y * move_speed)] == '0')
		all->plr->y -= plr->dir_y * move_speed;
}

void	move_a(t_all *all, t_plr *plr)
{
	all->plr->x -= plr->plane_x * move_speed;
	all->plr->y -= plr->plane_y * move_speed;
}

void	move_d(t_all *all, t_plr *plr)
{
	all->plr->x += plr->plane_x * move_speed;
	all->plr->y += plr->plane_y * move_speed;
}
