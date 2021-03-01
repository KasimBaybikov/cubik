/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_make.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 16:34:00 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/01 17:11:46 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_all *all, t_textures *t, char *path)
{
	int fd;

	if ((fd = open(path, 1)) == -1)
		error(3);
	close(fd);
	if (path != 0)
	{
		t->img_ptr = mlx_xpm_file_to_image(all->win->mlx, path, &t->width, &t->height);
		t->img_data = mlx_get_data_addr(t->img_ptr, &t->bpp, &t->line_len, &t->endian);
	}
}

void	textures_make(t_all *all)
{
	load_texture(all, all->north, all->tex->no);
	load_texture(all, all->south, all->tex->so);
	load_texture(all, all->west, all->tex->we);
	load_texture(all, all->east, all->tex->ea);
}
