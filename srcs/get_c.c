/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:50:11 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/06 20:16:02 by rvernon          ###   ########.fr       */
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

static void characters_fc(char *line, t_all *all)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == 'C' || line[i] == ',' || (line[i] <= '9' && line[i] >= '0'))
			i++;
		else
			error(3, all);
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

int		get_c_color(t_all *all, char *line)
{
	int i;
	char* tmp = line + 1;

	while (*tmp)
	{
		tmp = skip_spaces(tmp);
		if (*tmp < '0' || *tmp > '9')
			return (1);
		if (all->clr->c_r == -1)
			all->clr->c_r = ft_atoi(tmp);
		else if (all->clr->c_g == -1)
			all->clr->c_g = ft_atoi(tmp);
		else if (all->clr->c_b == -1)
		{
			all->clr->c_b = ft_atoi(tmp);
			break;
		}
		tmp = skip_numbers(tmp);
		tmp = skip_spaces(tmp);
		if (*tmp != ',')
			return (1);
		tmp = skip_dots(tmp);
	}
	return (0);
}

void	get_c(t_all *all, char *line, t_key *key)
{
	int i;

	key->c = 0;
	key->flag++;
	i = 0;
	characters_fc(line, all);
	if (find_dot(line) != 2)
		error(3, all);
	if (find_numbers(line) != 4)
		error(3, all);
	if (get_c_color(all, line) != 0)
		error(3, all);
}
