/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:07:16 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/28 11:19:23 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_up(int key, t_all *all)
{
	if (key == ESC_KEY)
		all->hook->esc = 0;
	if (key == W_KEY)
		all->hook->w = 0;
	if (key == A_KEY)
		all->hook->a = 0;
	if (key == S_KEY)
		all->hook->s = 0;
	if (key == D_KEY)
		all->hook->d = 0;
	if (key == LEFT_KEY)
		all->hook->left= 0;
	if (key == RIGHT_KEY)
		all->hook->right = 0;
	if (key == SHIFT_KEY)
	{
		all->plr->move_speed = 0.05;
		all->hook->shift = 0;
	}
	return (0);
}
