/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:39:53 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/03/08 14:31:54 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	all_mlx(t_all *all)
{
	all->win->mlx = mlx_init();
	if (all->screen == 0)
		all->win->win =
		mlx_new_window(all->win->mlx, all->win->w, all->win->h, "cub3D");
	all->img->img = mlx_new_image(all->win->mlx, all->win->w, all->win->h);
	all->img->addr = mlx_get_data_addr(all->img->img, &all->img->bpp,
			&all->img->line_len, &all->img->endian);
	all->z_buf = malloc(sizeof(float) * all->win->w);
}

int		cross_button(t_all *all)
{
	free_all(all);
	sleep(3);
	exit(0);
	return (0);
}

void	start(char *map_name, t_all *all)
{
	int fd;

	fd = 0;
	if ((fd = open(map_name, O_RDONLY)) == -1)
		error(2, all);
	parse_file(all, fd);
	parse_map(all, fd);
	close(fd);
	all_mlx(all);
	textures_make(all);
	mlx_do_key_autorepeatoff(all->win->mlx);
	if (all->screen == 0)
	{
		mlx_hook(all->win->win, 2, 0, &key_down, all);
		mlx_hook(all->win->win, 17, 0, &cross_button, all);
		mlx_hook(all->win->win, 3, 0, &key_up, all);
		mlx_loop_hook(all->win->mlx, &calculate, all);
		mlx_loop(all->win->mlx);
	}
	else
		calculate(all);
}
