/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:20:37 by kasimbayb         #+#    #+#             */
/*   Updated: 2020/12/21 23:01:33 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main()
{
	void    *mlx;
    void    *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 600, "Cub3D");
    mlx_loop(mlx);
}
