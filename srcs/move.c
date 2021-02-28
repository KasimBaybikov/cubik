/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:48:46 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/28 11:19:42 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_w(t_all *all, t_plr *plr)
{
	float step;

	step = 0.11;
	if (all->map[(int)(all->plr->y)][(int)(all->plr->x + plr->dir_x * step)] != '1')
		all->plr->x += plr->dir_x * plr->move_speed;
	if (all->map[(int)(all->plr->y + plr->dir_y * step)][(int)(all->plr->x)] != '1')
		all->plr->y += plr->dir_y * plr->move_speed;
}

void	move_s(t_all *all, t_plr *plr)
{
	float step;

	step = 0.11;
	if (all->map[(int)(all->plr->y)][(int)(all->plr->x - plr->dir_x * step)] != '1')
		all->plr->x -= plr->dir_x * plr->move_speed;
	if (all->map[(int)(all->plr->y - plr->dir_y * step)][(int)(all->plr->x)] != '1')
		all->plr->y -= plr->dir_y * plr->move_speed;
}

void	move_a(t_all *all, t_plr *plr)
{
	float step;

	step = 0.11;
	if (all->map[(int)plr->y][(int)(plr->x - plr->plane_x * step)] != '1')
		all->plr->x -= plr->plane_x * plr->move_speed;
	if (all->map[(int)(plr->y - plr->plane_y * step)][(int)(plr->x)] != '1')
		all->plr->y -= plr->plane_y * plr->move_speed;
}

void	move_d(t_all *all, t_plr *plr)
{
	float step;

	step = 0.11;
	if (all->map[(int)plr->y][(int)(plr->x + plr->plane_x * step)] != '1')
		all->plr->x += plr->plane_x * plr->move_speed;
	if (all->map[(int)(plr->y + plr->plane_y * step)][(int)(plr->x)] != '1')
		all->plr->y += plr->plane_y * plr->move_speed;
}
