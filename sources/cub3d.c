/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:18:30 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/01/10 16:57:30 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int get_pos_player(t_all *all)
{
	int x = -1;
	int y = -1;

	while (all->map[++y])
	{
		while (all->map[y][++x])
		{
			if (all->map[y][x] == 'N')
			{
				all->plr->x = (float)x * RECT;
				all->plr->y = (float)y * RECT;
				all->plr->a = 3*PI/2;
			}
			else if (all->map[y][x] == 'W')
			{
				all->plr->x = (float)x * RECT;
				all->plr->y = (float)y * RECT;
				all->plr->a = PI;
			}
			else if (all->map[y][x] == 'S')
			{
				all->plr->x = (float)x * RECT;
				all->plr->y = (float)y * RECT;
				all->plr->a = PI/2;
			}
			else if (all->map[y][x] == 'E')
			{
				all->plr->x = (float)x * RECT;
				all->plr->y = (float)y * RECT;
				all->plr->a = 0;
			}
		}
		x = -1;
	}
	return (0);
}

void	get_params(char *name_map)
{
	int		fd;
	t_all all;
	
	init_all(&all);
	fd = 0;
	if ((fd = open(name_map, O_RDONLY)) == -1)
		return (ft_error(2));
	get_lstmap(fd, &all);
}

int		check_map_name(char *name)
{
	int i;

	i = -1;
	while (name && *name && *name != '.')
		name++;
	if (*name == '.')
		name++;
	if (ft_strcmp(name, "cub") == 0)
		return (1);
	else
		ft_error(1);
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 1)
		ft_error(1);
	else if (argc == 2 && check_map_name(argv[1]) == 1)
		get_params(argv[1]);
	return (0);
}
