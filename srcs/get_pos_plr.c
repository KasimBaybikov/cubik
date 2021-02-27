/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_plr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:13:58 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/27 13:04:28 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dir_w(t_plr *plr)
{
	plr->dir_x = -1;
	plr->dir_y = 0;
	plr->plane_x = 0;
	plr->plane_y = -0.66;
}

void	dir_e(t_plr *plr)
{
	plr->dir_x = 1;
	plr->dir_y = 0;
	plr->plane_x = 0;
	plr->plane_y = 0.66;
}

void	dir_n(t_plr *plr)
{
	plr->dir_x = 0;
	plr->dir_y = -1;
	plr->plane_x = 0.66;
	plr->plane_y = 0;
}

void	dir_s(t_plr *plr)
{
	plr->dir_x = 0;
	plr->dir_y = 1;
	plr->plane_x = -0.66;
	plr->plane_y = 0;
}

void	get_xy(int i, int j, t_all *all, char dir)
{
	all->plr->x = j;
	all->plr->y = i;
	if (dir == 'W')
		dir_w(all->plr);
	if (dir == 'E')
		dir_e(all->plr);
	if (dir == 'N')
		dir_n(all->plr);
	if (dir == 'S')
		dir_s(all->plr);
}

int		get_pos_plr(t_all *all)
{
	int i;
	int j;
	int flag;
	char dir;

	i = 0;
	j = 0;
	flag = 0;
	while (all->map[i])
	{
		while (all->map[i][j])
		{
			if (all->map[i][j] == 'W' || all->map[i][j] == 'E' ||all->map[i][j] == 'N' ||all->map[i][j] == 'S')
			{
				dir = all->map[i][j];
				flag++;
				get_xy(i, j, all, dir);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (flag);
}
