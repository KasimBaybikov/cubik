/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:45:17 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/08 13:39:02 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_name(char *name, t_all *all)
{
	while (name && *name && *name != '.')
		name++;
	if (*name == '.')
		name++;
	if (ft_strcmp(name, "cub") == 0)
		return (1);
	else
		error(1, all);
	return (0);
}

int	main(int ac, char **av)
{
	t_all all;

	init_all(&all);
	if (ac == 1)
		error(1, &all);
	else if (ac == 2 && check_map_name(av[1], &all) == 1)
	{
		start(av[1], &all);
	}
	else if (ac == 3 && check_map_name(av[2], &all) == 1 &&
			ft_strcmp(av[1], "--save") == 0)
	{
		screen(&all, av[2]);
	}
	else
		error(1, &all);
}
