/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:18:31 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/17 13:28:55 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

void            my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
    char    *dst;

    dst = all->win->addr + (y * all->win->line_length + x * (all->win->bpp / 8));
    *(unsigned int*)dst = color;
}
