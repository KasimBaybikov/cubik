/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celling_paint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:45:06 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/27 15:01:12 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ceiling_paint(t_all *all)
{
	int x;
	int y;
	int color;

	x = 0;
	y = 0;
	color = rgb_make(0, all->clr->c_r, all->clr->c_g, all->clr->c_b);
	while (x < all->win->w)
	{
		while (y < all->win->h / 2)
		{
			my_mlx_pixel_put(all, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}
