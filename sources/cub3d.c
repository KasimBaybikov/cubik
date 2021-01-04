/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:18:30 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/01/04 20:47:11 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int pos_player(char **map, int i, int j)
{
	if (map[i][j] == 'N')
		return (1);
	else if (map[i][j] == 'W')
		return (2);
	else if (map[i][j] == 'S')
		return (3);
	else if (map[i][j] == 'E')
		return (4);
	return (0);
}

void	get_params(char *name_map)
{
	int		fd;
	t_all all;
	
	init_all(&all);
	ft_printf("%d\n%d\n%d\n%d\n", all.plr->x, all.plr->y, all.plr->a, all.win->height);
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
