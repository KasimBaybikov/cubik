/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:57:24 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/26 20:33:15 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mini_map(t_all *all, char **map)
{
	int i = 0;
	int j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '1')
				my_mlx_pixel_put(all, j, i, rgb_make(0, 101, 0, 101));
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->img->img, 0, 0);
}

void	all_mlx(t_all *all)
{
	all->win->mlx = mlx_init();
	all->win->win = mlx_new_window(all->win->mlx, all->win->w, all->win->h, "cub3D");
	all->img->img = mlx_new_image(all->win->mlx, all->win->w, all->win->h);
	all->img->addr = mlx_get_data_addr(all->img->img, &all->img->bpp, &all->img->line_len, &all->img->endian);
}

void	ray_dir(t_all *all, t_plr *plr, int x)
{
	plr->camera_x = 2 * x / (double)all->win->w - 1;
	plr->ray_dir_x = plr->dir_x + plr->plane_x * plr->camera_x;
	plr->ray_dir_y = plr->dir_y + plr->plane_y * plr->camera_x;
	plr->map_x = all->plr->x;
	plr->map_y = all->plr->y;
	plr-> delta_dist_x = (plr->ray_dir_y == 0) ? 0 : ((plr->ray_dir_x == 0) ? 1 : fabs(1 / plr->ray_dir_x));
	plr-> delta_dist_y = (plr->ray_dir_x == 0) ? 0 : ((plr->ray_dir_y == 0) ? 1 : fabs(1 / plr->ray_dir_y));
	plr-> delta_dist_y = fabs(1 / plr->ray_dir_y);
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
			//printf("%f\n", plr->side_dist_x);
		}
		else
		{
			plr->side_dist_y += plr->delta_dist_y;
			plr->map_y += plr->step_y;
			plr->side = 1;
			//printf("%f\n", plr->side_dist_y);
		}
		if (all->map[plr->map_x][plr->map_y] == '1')
			plr->hit = 1;
		if (plr->side == 0)
			plr->perp_wall_dist = (plr->map_x - plr->x + (1 - plr->step_x) / 2) / plr->ray_dir_x;
		else
			plr->perp_wall_dist = (plr->map_y - plr->y + (1 - plr->step_y) / 2) / plr->ray_dir_y;
	}
}
void	calculate(t_all *all)
{
	int x;

	x = 0;
	all_mlx(all);
	while (x < all->win->w)
	{
		ray_dir(all, all->plr, x);
		side_dist_x(all->plr);
		raycast(all, all->plr);
		printf("%f\n", all->plr->perp_wall_dist);
		x++;
	}
	mlx_loop(all->win->mlx);
}
