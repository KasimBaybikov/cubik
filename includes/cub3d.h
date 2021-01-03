/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:36:17 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/01/04 01:42:08 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/includes/libftprintf.h"
# include "../libft/get_next_line.h"
# include <fcntl.h>

typedef struct s_win
{
    int width;
    int height;
	void *mlx;
	void *win;
}               t_win;
/*
    **Color
*/
int		get_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
void ft_error(int error);
/*
    **Inits
*/
void	init_window(t_win *window);

#endif
