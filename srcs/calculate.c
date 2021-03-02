/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:57:24 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/02 19:35:18 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_dir(t_all *all, t_plr *plr, int x)
{
	plr->camera_x = 2 * x / (double)all->win->w - 1;
	plr->ray_dir_x = plr->dir_x + plr->plane_x * plr->camera_x;
	plr->ray_dir_y = plr->dir_y + plr->plane_y * plr->camera_x;
	plr->map_x = (int)all->plr->x;
	plr->map_y = (int)all->plr->y;
	plr->delta_dist_x = fabs(1 / plr->ray_dir_x);
	plr->delta_dist_y = fabs(1 / plr->ray_dir_y);
	//plr-> delta_dist_y = fabs(1 / plr->ray_dir_y);
	plr->hit = 0;
}

void	side_dist_x(t_plr *plr)
{
	if (plr->ray_dir_x < 0)
	{
		plr->step_x = -1;
		plr->side_dist_x = (plr->x - plr->map_x) * plr->delta_dist_x;
	}
	else
	{
		plr->step_x = 1;
		plr->side_dist_x = (plr->map_x + 1.0 - plr->x) * plr->delta_dist_x;
	}
	if (plr->ray_dir_y < 0)
	{
		plr->step_y = -1;
		plr->side_dist_y = (plr->y - plr->map_y) * plr->delta_dist_y;
	}
	else
	{
		plr->step_y = 1;
		plr->side_dist_y = (plr->map_y + 1.0 - plr->y) * plr->delta_dist_y;
	}
}

void	raycast(t_all *all, t_plr *plr)
{
	while (plr->hit == 0)
	{
		if (plr->side_dist_x < plr->side_dist_y)
		{
			plr->side_dist_x += plr->delta_dist_x;
			plr->map_x += plr->step_x;
			plr->side = 0;
		}
		else
		{
			plr->side_dist_y += plr->delta_dist_y;
			plr->map_y += plr->step_y;
			plr->side = 1;
		}
		if (all->map[plr->map_y][plr->map_x] == '1')
			plr->hit = 1;
	}
	if (plr->side == 0)
		plr->perp_wall_dist = (plr->map_x - plr->x + (1 - plr->step_x) / 2) / plr->ray_dir_x;
	else
		plr->perp_wall_dist = (plr->map_y - plr->y + (1 - plr->step_y) / 2) / plr->ray_dir_y;
	plr->line_height = (int) (all->win->h / plr->perp_wall_dist);
}

void	draw_start_end(t_all *all, t_plr *plr)
{
	plr->draw_start = -plr->line_height / 2 + all->win->h / 2;
	if (plr->draw_start < 0)
		plr->draw_start = 0;
	plr->draw_end = plr->line_height / 2 + all->win->h / 2;
	if (plr->draw_end >= all->win->h)
		plr->draw_end = all->win->h - 1;
}

void	texture_coordinates(int x, t_all *all, t_plr *plr, t_textures *t)
{
	if (all->plr->side == 0)
		plr->wall_x = all->plr->y + all->plr->perp_wall_dist * all->plr->ray_dir_y;
	else 
		plr->wall_x= all->plr->x + all->plr->perp_wall_dist * all->plr->ray_dir_x;
	plr->wall_x -= floor(plr->wall_x);
	plr->tex_x = (int)(plr->wall_x * (double)t->width);
	if (all->plr->side == 0 && all->plr->ray_dir_x > 0)
		plr->tex_x = t->width - plr->tex_x - 1;
	if (all->plr->side == 0 && all->plr->ray_dir_x < 0)
		plr->tex_x = t->width - plr->tex_x - 1;
	plr->step =  1.0 * t->height / plr->line_height;
	plr->tex_pos = plr->step * (plr->draw_start - all->win->h / 2 + plr->line_height / 2);
}

void	fence(t_all *all, int draw_start, int draw_end, int x, int color)
{
	int i;
	float y;
	t_textures *t;

	i = draw_start;
	y = 0.0;
	if (all->plr->side == 0 && all->plr->step_x > 0)
		t = all->east;
	if (all->plr->side == 0 && all->plr->step_x < 0)
		t = all->west;
	if (all->plr->side == 1 && all->plr->step_y < 0)
		t = all->north;
	if (all->plr->side == 1 && all->plr->step_y > 0)
		t = all->south;
	texture_coordinates(x, all, all->plr, t);
	while (i < draw_end)
	{
		all->plr->tex_y = (int)all->plr->tex_pos & (t->height - 1);
		all->plr->tex_pos += all->plr->step;
		color = ((int*)(t->img_data))[t->height * all->plr->tex_y + all->plr->tex_x];
		pixel_put(all, x, i, color);
		i++;
	}
}



int		calculate(t_all *all)
{
	int x;

	x = 0;
	floor_paint(all);
	ceiling_paint(all);
	new_keys(all, all->plr);
	while (x < all->win->w)
	{
		ray_dir(all, all->plr, x);
		side_dist_x(all->plr);
		raycast(all, all->plr);
		draw_start_end(all, all->plr);
		fence(all, all->plr->draw_start, all->plr->draw_end, x, rgb_make(0, 255, 176, 0));
		sprite_casting(all);
		x++;
	}
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->img->img, 0, 0);
	return (0);
}
