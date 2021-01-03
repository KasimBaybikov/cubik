/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:18:30 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/01/03 21:36:55 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <fcntl.h>

void	get_params(char *map)
{
	int		fd;
	char	*line;

	fd = 0;
	if ((fd = open(map, O_RDONLY)) == -1)
		return (ft_error(2));
	while (get_next_line(fd, &line))
	{
		ft_printf("%s\n", line);
	}
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
