/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:39:53 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/03/01 19:47:58 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_name(char *name)
{
	while (name && *name && *name != '.')
		name++;
	if (*name == '.')
		name++;
	if (ft_strcmp(name, "cub") == 0)
		return (1);
	else
		error(1);
	return (0);
}
void	all_mlx(t_all *all)
{
	all->win->mlx = mlx_init();
	all->win->win = mlx_new_window(all->win->mlx, all->win->w, all->win->h, "cub3D");
	all->img->img = mlx_new_image(all->win->mlx, all->win->w, all->win->h);
	all->img->addr = mlx_get_data_addr(all->img->img, &all->img->bpp, &all->img->line_len, &all->img->endian);
}

void start(char *map_name, t_all *all)
{
	int fd;

	fd = 0;
	init_all(all);
	if ((fd = open(map_name, O_RDONLY)) == -1)
		error(2);
	parse_file(all, fd);
	parse_map(all, fd);
	close(fd);
	all_mlx(all);
	textures_make(all);
	mlx_do_key_autorepeatoff(all->win->mlx);
	mlx_hook(all->win->win, 2, 0, &key_down, all);
	mlx_hook(all->win->win, 3, 0, &key_up, all);
	mlx_loop_hook(all->win->mlx, &calculate, all);
	mlx_loop(all->win->mlx);
}
