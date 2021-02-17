/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:30:30 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/17 13:49:26 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_win(t_win *win)
{
	win->mlx = mlx_init();
	win->win = 0;
	win->w = 0;
	win->h = 0;
}

static void	init_plr(t_plr *plr)
{
	plr->x = 0.0;
	plr->y = 0.0;
	plr->a = 0.0;
}

void	init_all(t_all *all)
{
	if (!(all->win = malloc(sizeof(t_win) * 1)))
		return;
	if (!(all->plr = malloc(sizeof(t_all) * 1)))
		return;
	init_win(all->win);
	init_plr(all->plr);
	all->map = 0;

}
