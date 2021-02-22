/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:32:21 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/22 22:11:43 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int	get_count_sprites(t_all *all)
{
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
void	get_sprites(t_all *all)
{
	int count;

	count = get_count_sprites(all);

	
}
