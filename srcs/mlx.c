/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:18:31 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/26 13:19:19 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
    char    *dst;

    dst = all->img->addr + (y * all->img->line_len + x * (all->img->bpp / 8));
    *(unsigned int*)dst = color;
}

int		rgb_make(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}
