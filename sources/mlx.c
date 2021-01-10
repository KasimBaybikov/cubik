/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:26:05 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/01/10 17:28:05 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void            my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
    char    *dst;

    dst = all->win->->adr + (y * all->data->line_length + x *
			(all->data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
    mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
