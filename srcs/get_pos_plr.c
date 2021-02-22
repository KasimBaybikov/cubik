/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_plr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:13:58 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/22 17:32:03 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	get_xy(int i, int j, t_all *all)
{
	all->plr->x = j;
	all->plr->y = i;
}

void	get_pos_plr(t_all *all)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (all->map[i])
	{
		while (all->map[i][j])
		{
			if (all->map[i][j] == 'W')
				get_xy(i, j, all);
			if (all->map[i][j] == 'E')
				get_xy(i, j, all);
			if (all->map[i][j] == 'S')
				get_xy(i, j, all);
			if (all->map[i][j] == 'N')
				get_xy(i, j, all);
			j++;
		}
		j = 0;
		i++;
	}
}
