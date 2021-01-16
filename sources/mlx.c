/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:26:05 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/01/16 19:50:47 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void            my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
    char    *dst;
	

	dst = all->win->addr + (y * all->win->line_length + x * (all->win->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
