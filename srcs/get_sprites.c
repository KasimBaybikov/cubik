/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:32:21 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/02 20:00:21 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_count_sprites(t_all *all)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (all->map[i])
	{
		while (all->map[i][j])
		{
			if (all->map[i][j] == '2')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

void	get_sprites(t_all *all, int x, int y, int i)
{
	int count;

	count = get_count_sprites(all);
	free(all->spr);
	all->spr = malloc(sizeof(t_spr) * (count));
	while (all->map[x])
	{
		while (all->map[x][y])
		{
			if (all->map[x][y] == '2')
			{
				all->spr[i].x = x;
				all->spr[i].y = y;
				i++;
			}
			y++;
		}
		y = 0;
		x++;
	}
}
