/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_plr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:13:58 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/23 16:05:44 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	get_xy(int i, int j, t_all *all)
{
	all->plr->x = j;
	all->plr->y = i;
}

int		get_pos_plr(t_all *all)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	while (all->map[i])
	{
		while (all->map[i][j])
		{
			if (all->map[i][j] == 'W' || all->map[i][j] == 'E' ||all->map[i][j] == 'N' ||all->map[i][j] == 'S')
			{
				flag++;
				get_xy(i, j, all);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (flag);
}