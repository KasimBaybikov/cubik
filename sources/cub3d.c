/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:18:30 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/01/06 00:39:06 by kasimbayb        ###   ########.fr       */
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
			//printf("Y: %d X: %d\n", y, x);
			if (all->map[y][x] == 'N')
			{
				printf("Y: %d X: %d\n", y, x);
				all->plr->x = (float)x;
				all->plr->y = (float)y;
			}
			else if (all->map[y][x] == 'W')
			{
				//printf("Y: %d X: %d\n", y, x);
				return (2);
			}
			else if (all->map[y][x] == 'S')
			{
				//printf("Y: %d X: %d\n", y, x);
				return (3);
			}
			else if (all->map[y][x] == 'E')
			{
				//printf("Y: %d X: %d\n", y, x);
				return (3);
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
	//printf("print: \n%f\n%f\n%d\n%p\n...\n", all.plr->x, all.plr->y, all.plr->a, all.win->win);
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
	{
		get_params(argv[1]);
	}
	return (0);
}
