/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initials.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 01:14:39 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/01/04 20:45:55 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_window(t_win *window)
{
	window->mlx = NULL;
	window->win = NULL;
	window->width = 0;
	window->height = 0;
}

void init_plr(t_plr *plr)
{
	plr->x = 0;
	plr->y = 0;
	plr->a = 0;
}

void	init_all(t_all *all)
{
	if (!(all->win = malloc(sizeof(t_win) * 1)))
		return ;
	if (!(all->plr = malloc(sizeof(t_plr) * 1)))
		return ;
	init_window(all->win);
	init_plr(all->plr);
	all->map = 0;
}
