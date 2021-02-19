/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:01:43 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/19 21:44:41 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_r(t_all *all, char *line)
{
	char **split;
	int i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 3)
	{
		error(3);
		exit(1);
	}
	all->win->w = ft_atoi(split[1]);
	all->win->h = ft_atoi(split[2]);
	free(split);
}

void	get_no(t_all *all, char *line)
{
	char **split;
	int i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
	{
		error(3);
		exit(1);
	}
	all->tex->no = ft_strdup(split[1]);
	free(split);
}

void	get_so(t_all *all, char *line)
{
	char **split;
	int i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
	{
		error(3);
		exit(1);
	}
	all->tex->so = ft_strdup(split[1]);
	free(split);
}

void	get_we(t_all *all, char *line)
{
	char **split;
	int i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
	{
		error(3);
		exit(1);
	}
	all->tex->we = ft_strdup(split[1]);
	free(split);
}

void	get_ea(t_all *all, char *line)
{
	char **split;
	int i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
	{
		error(3);
		exit(1);
	}
	all->tex->ea = ft_strdup(split[1]);
	free(split);
}

void	get_s(t_all *all, char *line)
{
	char **split;
	int i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
	{
		error(3);
		exit(1);
	}
	all->tex->spr = ft_strdup(split[1]);
	free(split);
}


