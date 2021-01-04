/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:05:21 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/01/04 14:22:20 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		key_press(int key, t_win *window, t_plr *plr)
{
	//mlx_clear_window(window->mlx, window->win);
	(void)window;
	if (key == 13) //w
		plr->x += 1;
	else if (key == 1) //s
		plr->x += 10;
	else if (key == 0) //a
		plr->x -= 1;
	else if (key == 2) //d
		plr->x -= 10;;
	if (key == 53)
		exit(0);
	//ft_printf("%d\n", plr->x);
	return (0);
}

void	draw_player(t_win *window, int plrsize, int x, int y, int color)
{
	int i;
	int j;
	t_plr plr;

	i = -1;
	j = -1;
	plr.x = x;
	plr.y = y;
	while (++i < plrsize)
	{
		while (++j < plrsize)
		{		
			mlx_pixel_put(window->mlx, window->win, (plr.x * RECT) + i, (plr.y*RECT) + j, color);
		}
		j = -1;
	}
	mlx_key_hook(window->win, key_press, window);
}

void	draw_pix(t_win *window, int rectsize, int i, int j, int color)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (++x < rectsize)
	{
		while (++y < rectsize)
		{		
			mlx_pixel_put(window->mlx, window->win, (i * RECT) + x, (j*RECT) + y, color);
		}
		y = -1;
	}
}

void	draw_map(char **map)
{
	int i;
	int j;
	t_win window;

	i = -1;
	j = -1;
	init_window(&window);
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 800, 600, "Cub3D");
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				draw_pix(&window, RECT, j, i, get_trgb(0, 255, 150, 200));
			if (pos_player(map, i, j))
				draw_player(&window, 10, j, i, get_trgb(0, 10, 20, 200));
		}
		j = -1;
	}
	mlx_loop(window.mlx);
}
