/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:26:05 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/01/07 15:06:54 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void            my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
    char    *dst;

    dst = all->win->->adr + (y * all->data->line_length + x * (all->data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
    mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
}

int             main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
    img.img = mlx_new_image(mlx, 800, 600);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	int x = 0;
	while (x++ < 600)
    	my_mlx_pixel_put(&img, x, 5, 0x00FF0000);
    mlx_loop(mlx);
}
