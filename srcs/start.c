/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:39:53 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/02/26 16:55:16 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_name(char *name)
{
	while (name && *name && *name != '.')
		name++;
	if (*name == '.')
		name++;
	if (ft_strcmp(name, "cub") == 0)
		return (1);
	else
		error(1);
	return (0);
}

void start(char *map_name, t_all *all)
{
	int fd;

	fd = 0;
	init_all(all);
	if ((fd = open(map_name, O_RDONLY)) == -1)
		error(2);
	parse_file(all, fd);
	parse_map(all, fd);
	calculate(all);
	close(fd);
}
