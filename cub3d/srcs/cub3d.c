/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:39:53 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/02/15 15:41:37 by kasimbayb        ###   ########.fr       */
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

void start(char *s)
{
	(void)s;
	return ;
}

int	main(int ac, char **av)
{
	if (ac == 1)
		error(1);
	else if (ac == 2 && check_map_name(av[1]) == 1)
		start(av[1]);
	//else if (argc == 3 && check_map_name(av[2]) == 1)
	//	screen(av[2]);

}
