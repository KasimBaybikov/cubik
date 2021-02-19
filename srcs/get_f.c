/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 21:42:22 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/19 21:43:18 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_dot(char **split)
{
	int i;
	int j;
	int dot;

	i = 0;
	j = 0;
	dot = 0;
	while (split[i])
	{
		while (split[i][j])
		{
			if (split[i][j] == ',')
				dot++;
			j++;
		}
		j = 0;
		i++;
	}
	return (dot);
}

int find_numbers(char ** split)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (split[i])
	{
		if ((ft_strcmp(split[i], ",")) == 0)
		{
			i++;
			continue ;
		}
		res++;
		i++;
	}
	return (res);
}

void	get_f_colors(t_all *all, char *s_color)
{
	if (ft_atoi(s_color) < 0 || ft_atoi(s_color) > 255)
	{
		error(3);
		exit(1);
	}
	else if (all->clr->f_r == -1)
		all->clr->f_r = ft_atoi(s_color);
	else if (all->clr->f_g == -1)
		all->clr->f_g = ft_atoi(s_color);
	else if (all->clr->f_b == -1)
		all->clr->f_b = ft_atoi(s_color);

}

void	get_f(t_all *all, char *line)
{
	char **split;
	int dot;
	int numbers;
	int i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	dot = find_dot(split);
	numbers = find_numbers(split);
	if (i > 6 || dot != 2 || numbers != 4)
	{
		error(3);
		exit(1);
	}
	i = 1;
	while (split[i])
	{
		if (split[i][0] == ',')
		{
			i++;
			continue ;
		}
		get_f_colors(all, split[i]);
		i++;
	}
	free(split);
}
