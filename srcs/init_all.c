/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:30:30 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/01 22:26:32 by rvernon          ###   ########.fr       */
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
	win->w = 0;
	win->h = 0;
}

static	void	init_plr(t_plr *plr)
{
	plr->x = 0.0;
	plr->y = 0.0;
	plr->dir_x = 0;
	plr->dir_y = 0;
	plr->plane_x = 0;
	plr->plane_y = 0;
	plr->camera_x = 0;
	plr->ray_dir_x = 0;
	plr->ray_dir_y = 0;
	plr->side_dist_x = 0;
	plr->delta_dist_x = 0;
	plr->delta_dist_y = 0;
	plr->side_dist_y = 0;
	plr->perp_wall_dist = 0;
	plr->line_height = 0;
	plr->draw_start = 0;
	plr->draw_end = 0;
	plr->step_x = 0;
	plr->step_y = 0;
	plr->hit = 0;
	plr->side = 0;
	plr->map_x = 0;
	plr->map_y = 0;
	plr->move_speed = 0.05;
	plr->tex_num = 0;
	plr->wall_x = 0;
	plr->tex_x = 0;
	plr->step = 0;
	plr->tex_pos = 0;
	plr->tex_y = 0;
}

static	void	init_clr(t_clr *clr)
{
	clr->f_r = -1;
	clr->f_g = -1;
	clr->f_b = -1;
	clr->c_r = -1;
	clr->c_g = -1;
	clr->c_b = -1;
}

static	void	init_hook(t_hook *hook)
{
	hook->esc = 0;
	hook->w = 0;
	hook->a = 0;
	hook->s = 0;
	hook->d = 0;
	hook->left = 0;
	hook->right = 0;
	hook->shift = 0;
}

static	void	init_textures(t_textures *t)
{
	t->img_data = 0;
	t->img_ptr = 0;
	t->data = 0;
	t->line_len = 0;
	t->endian = 0;
	t->width = 0;
	t->height = 0;
	t->bpp = 0;
}

void	init_all(t_all *all)
{
	all->win = malloc(sizeof(t_win) * 1);
	all->plr = malloc(sizeof(t_plr) * 1);
	all->tex = malloc(sizeof(t_tex) * 1);
	all->clr = malloc(sizeof(t_clr) * 1);
	all->img = malloc(sizeof(t_img) * 1);
	all->hook = malloc(sizeof(t_hook) * 1);
	all->north = malloc(sizeof(t_textures) * 1);
	all->south = malloc(sizeof(t_textures) * 1);
	all->west = malloc(sizeof(t_textures) * 1);
	all->east = malloc(sizeof(t_textures) * 1);
	init_win(all->win);
	init_plr(all->plr);
	init_tex(all->tex);
	init_clr(all->clr);
	init_hook(all->hook);
	init_textures(all->north);
	init_textures(all->south);
	init_textures(all->west);
	init_textures(all->east);
	all->spr = 0;
	all->map = 0;
	all->map_w = 0;
	all->map_h = 0;
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
	key->flag = 0;
}
