/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 13:08:12 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/01 16:04:04 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_down(int key, t_all *all)
{
	if (key == ESC_KEY)
		all->hook->esc = 1;
	if (key == W_KEY)
		all->hook->w = 1;
	if (key == A_KEY)
		all->hook->a = 1;
	if (key == S_KEY)
		all->hook->s = 1;
	if (key == D_KEY)
		all->hook->d = 1;
	if (key == LEFT_KEY)
		all->hook->left= 1;
	if (key == RIGHT_KEY)
		all->hook->right = 1;
	if (key == SHIFT_KEY)
		all->hook->shift = 1;
	return (0);
}
