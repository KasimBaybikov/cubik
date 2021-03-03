/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:18:31 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/03 12:05:45 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

void	pixel_put(t_all *all, int x, int y, int color)
{
    char    *dst;

    dst = all->img->addr + (y * all->img->line_len + x * (all->img->bpp / 8));
    *(unsigned int*)dst = color;
}

int		pixel_get(t_textures *t, int x, int y)
{
	char *ptr;
	ptr = t->img_data + (y * t->line_len + x * (t->bpp / 8));
	return (*(int *)ptr);
}

int		rgb_make(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}
