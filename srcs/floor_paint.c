/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:23:31 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/27 14:30:28 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_paint(t_all *all)
{
	int x;
	int y;
	int color;

	x = 0;
	y = 0;
	color = rgb_make(0, all->clr->f_r, all->clr->f_g, all->clr->f_b);
	while (x < all->win->w)
	{
		while (y < all->win->h / 2)
		{
			my_mlx_pixel_put(all, x, y, rgb_make(
		}
		y = 0;
		x++;
	}
