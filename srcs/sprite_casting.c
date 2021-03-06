/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:28:24 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/06 13:01:56 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_spr(t_sprite *sprr)
{
	sprr->spr_order = malloc(sizeof(int) * sprr->num_sprites);
	sprr->spr_dist = malloc(sizeof(float) * sprr->num_sprites);
}

void	sprite_dist(t_sprite *sprr, t_spr *spr, t_plr *plr)
{
	int i;

	i = 0;
	while (i < sprr->num_sprites)
	{
		sprr->spr_order[i] = i;
		sprr->spr_dist[i] = ((plr->x - spr[i].x) * (plr->x - spr[i].x) + (plr->y - spr[i].y) * (plr->y - spr[i].y));
		i++;
	}
}

void	sort_sprites(int *order, float *dist, int len)
{
	int i;
	int j;
	float tmp;
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (dist[i] < dist[j])
			{
				tmp = dist[i];
				dist[i] = dist[j];
				dist[j] = tmp;
				tmp = (float)order[i];
				order[i] = order[j];
				order[j] = (int)tmp;
			}
			j++;
		}
		i++;
	}
}

void	calc_sprite(t_all *all, t_sprite *s, int i)
{
	s->spr_x = all->spr[s->spr_order[i]].x - all->plr->x;	
	s->spr_y = all->spr[s->spr_order[i]].y - all->plr->y;	
	s->inv_det = 1.0 / (all->plr->plane_x * all->plr->dir_y - all->plr->dir_x * all->plr->plane_y);
	s->transform_x = s->inv_det * (all->plr->dir_y * s->spr_x - all->plr->dir_x * s->spr_y);
	s->transform_y = s->inv_det * (-all->plr->plane_y * s->spr_x + all->plr->plane_x * s->spr_y);
	s->spr_screen_x = (int)((all->win->w / 2) * (1 + s->transform_x / s->transform_y));
	s->spr_h  = (int)fabs(all->win->h / s->transform_y);
	s->spr_w = (int)fabs(all->win->h / s->transform_y);
	s->dr_start_y = -s->spr_h / 2 + all->win->h / 2;
	if (s->dr_start_y < 0)
		s->dr_start_y = 0;
	s->dr_end_y = s->spr_h / 2 + all->win->h / 2;
	if (s->dr_end_y >= all->win->h)
		s->dr_end_y = all->win->h - 1;
	s->dr_start_x = -s->spr_w / 2 + s->spr_screen_x;
	if (s->dr_start_x < 0)
		s->dr_start_x = 0;
	s->dr_end_x = s->spr_w / 2 + s->spr_screen_x;
	if (s->dr_end_x >= all->win->w)
		s->dr_end_x = all->win->w - 1;
}

void	draw_sprite(t_all *all, t_sprite *s, int stripe)
{
	int y;
	int color;

	y = s->dr_start_y;
	while (y < s->dr_end_y)
	{	
		s->d = (y) * 256 - all->win->h * 128 + s->spr_h * 128;
		s->tex_y = ((s->d * all->sprite->height) / s->spr_h) / 256;
		color = ((int*)all->sprite->img_data)[all->sprite->width * s->tex_y + s->tex_x];
		if (color != rgb_make(0, 0, 0, 0))
			pixel_put(all, s->stripe, y, color);
		y++;
	}
}

void	sprite_casting(t_all *all, t_sprite *s)
{
	int i;

	i = 0;
	init_spr(s);
	sprite_dist(s, all->spr, all->plr);
	sort_sprites(s->spr_order, s->spr_dist, s->num_sprites);
	while (i < s->num_sprites)
	{
		calc_sprite(all, s, i);
		s->stripe = s->dr_start_x;
		while (s->stripe < s->dr_end_x)
		{
			s->tex_x = (int)((256 * (s->stripe - (-s->spr_w / 2 + s->spr_screen_x)) * 64 / s->spr_w) / 256);
			if (s->transform_y > 0 && s->stripe > 0 && s->stripe < all->win->w && s->transform_y < all->z_buf[s->stripe])
			{
				draw_sprite(all, s, s->stripe); 
			}
			s->stripe++;
		}
		i++;
	}
	free(s->spr_order);
	free(s->spr_dist);
}
