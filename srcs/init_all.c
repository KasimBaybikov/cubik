/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:30:30 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/20 18:34:37 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void init_tex(t_tex *tex)
{
	tex->no = 0;
	tex->so = 0;
	tex->we = 0;
	tex->ea = 0;
	tex->spr = 0;

}

static	void	init_win(t_win *win)
{
	win->mlx = mlx_init();
	win->win = 0;
	win->w = 0;
	win->h = 0;
}

static	void	init_plr(t_plr *plr)
{
	plr->x = 0.0;
	plr->y = 0.0;
	plr->a = 0.0;
}

static	void init_clr(t_clr *clr)
{
	clr->f_r = -1;
	clr->f_g = -1;
	clr->f_b = -1;
	clr->c_r = -1;
	clr->c_g = -1;
	clr->c_b = -1;
}

void	init_all(t_all *all)
{
	if (!(all->win = malloc(sizeof(t_win) * 1)))
		return ;
	if (!(all->plr = malloc(sizeof(t_plr) * 1)))
		return ;
	if (!(all->tex = malloc(sizeof(t_tex) * 1)))
		return ;
	if (!(all->clr = malloc(sizeof(t_clr) * 1)))
		return ;
	init_win(all->win);
	init_plr(all->plr);
	init_tex(all->tex);
	init_clr(all->clr);
	all->map = 0;

}

void	init_key(t_key *key)
{
	key->r = 1;
	key->no = 1;
	key->so = 1;
	key->we = 1;
	key->ea = 1;
	key->s = 1;
	key->f = 1;
	key->c = 1;
}
