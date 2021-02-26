/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:57:24 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/26 13:24:05 by rvernon          ###   ########.fr       */
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
void	draw(t_all *all)
{
	all_mlx(all);
	mini_map(all, all->map);
	mlx_loop(all->win->mlx);
}
