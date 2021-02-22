/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:50:11 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/22 11:48:15 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		find_dot(char *line)
{
	int dot;
	int i;

	i = 0;
	dot = 0;
	while (line[i])
	{
		if (line[i] == ',')
			dot++;
		i++;
	}
	return (dot);
}

static void characters_fc(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == 'C' || line[i] == ',' || (line[i] <= '9' && line[i] >= '0'))
			i++;
		else
			error(3);
	}
}

static int find_numbers(char *line)
{
	int i;
	int res;
	int is_num;

	i = 0;
	is_num = 0;
	res = 0;
	while (line[i])
	{
		if ((line[i] != ' ' && line[i] != ',') && is_num == 0)
		{
			is_num = 1;
			res++;
		}
		else if (line[i] == ' ' || line[i] == ',')
			is_num = 0;
		i++;
	}
	return (res);
}

void	get_c_color(t_all *all, char *line)
{
	int is_num;

	is_num = 0;
	while(line && *line)
	{
		if (is_num == 0 && *line >= '0' && *line <= '9')
		{
			is_num = 1;
			if (ft_atoi(line) < 0 || ft_atoi(line) > 255)
			{
				error(3);
				exit(1);
			}
			else if (all->clr->c_r == -1)
				all->clr->c_r = ft_atoi(line);
			else if (all->clr->c_g == -1)
				all->clr->c_g = ft_atoi(line);
			else if (all->clr->c_b == -1)
				all->clr->c_b = ft_atoi(line);
		}
		else if (*line == ' ' || *line == ',')
			is_num = 0;
		line++;
	}
}

void	get_c(t_all *all, char *line, t_key *key)
{
	int i;

	key->c = 0;
	key->flag++;
	i = 0;
	characters_fc(line);
	if (find_dot(line) != 2)
		error(3);
	if (find_numbers(line) != 4)
		error(3);
	get_c_color(all, line);
}
