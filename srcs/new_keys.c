/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:43:35 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/04 16:51:07 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	shift_speed(t_all *all)
{
	all->plr->move_speed = 0.1;
}

void	right_turn(t_plr *plr)
{
	float old_dir_x;
	float old_plane_x;

	old_dir_x = plr->dir_x;
	plr->dir_x = plr->dir_x * cos(rot_speed) - plr->dir_y * sin(rot_speed);
	plr->dir_y = old_dir_x * sin(rot_speed) + plr->dir_y * cos(rot_speed);
	old_plane_x = plr->plane_x;
	plr->plane_x = plr->plane_x * cos(rot_speed) - plr->plane_y * sin(rot_speed);
	plr->plane_y = old_plane_x * sin(rot_speed) + plr->plane_y * cos(rot_speed);
}

void	left_turn(t_plr *plr)
{
	float old_plane_x;
	float old_dir_x;

	old_dir_x = plr->dir_x;
	plr->dir_x = plr->dir_x * cos(-rot_speed) - plr->dir_y * sin(-rot_speed);
	plr->dir_y = old_dir_x * sin(-rot_speed) + plr->dir_y * cos(-rot_speed);
	old_plane_x = plr->plane_x;
	plr->plane_x = plr->plane_x * cos(-rot_speed) - plr->plane_y * sin(-rot_speed);
	plr->plane_y = old_plane_x * sin(-rot_speed) + plr->plane_y * cos(-rot_speed);
}

void	new_keys(t_all *all, t_plr *plr)
{
	if (all->hook->esc)
		exit(0);
	if (all->hook->w)
		move_w(all, all->plr);
	if (all->hook->s)
		move_s(all, all->plr);
	if (all->hook->a)
		move_a(all, all->plr);
	if (all->hook->d)
		move_d(all, all->plr);
	if (all->hook->right)
		right_turn(all->plr);
	if (all->hook->left)
		left_turn(all->plr);
	if (all->hook->shift)
		shift_speed(all);
}
