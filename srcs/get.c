/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:01:43 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/08 13:12:51 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return ;
}

void	characters_r(char *line, t_all *all)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'R' || line[i] == ' ' ||
			(line[i] <= '9' && line[i] >= '0'))
			i++;
		else
			error(3, all);
	}
}

void	check_r(t_all *all, char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		error(3, all);
}

void	get_r(t_all *all, char *line, t_key *key)
{
	char **split;

	key->r = 0;
	key->flag++;
	characters_r(line, all);
	split = ft_split(line, ' ');
	check_r(all, split);
	if (ft_atoi(split[1]) < 0 || ft_atoi(split[1]) > 2560)
		all->win->w = 2560;
	else
		all->win->w = ft_atoi(split[1]);
	if (ft_atoi(split[2]) < 0 || ft_atoi(split[2]) > 1440)
		all->win->h = 1440;
	else
		all->win->h = ft_atoi(split[2]);
	if (all->win->w < 100 || all->win->h < 100)
	{
		all->win->w = 100;
		all->win->h = 100;
	}
	free_split(split);
}

void	get_no(t_all *all, char *line, t_key *key)
{
	char	**split;
	int		i;

	key->no = 0;
	key->flag++;
	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
		error(3, all);
	all->tex->no = ft_strdup(split[1]);
	free_split(split);
}

void	get_so(t_all *all, char *line, t_key *key)
{
	char	**split;
	int		i;

	key->so = 0;
	key->flag++;
	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
		error(3, all);
	all->tex->so = ft_strdup(split[1]);
	free_split(split);
}

void	get_we(t_all *all, char *line, t_key *key)
{
	char	**split;
	int		i;

	key->we = 0;
	key->flag++;
	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
		error(3, all);
	all->tex->we = ft_strdup(split[1]);
	free_split(split);
}

void	get_ea(t_all *all, char *line, t_key *key)
{
	char	**split;
	int		i;

	key->ea = 0;
	key->flag++;
	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
		error(3, all);
	all->tex->ea = ft_strdup(split[1]);
	free_split(split);
}

void	get_s(t_all *all, char *line, t_key *key)
{
	char	**split;
	int		i;

	key->s = 0;
	key->flag++;
	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
		error(3, all);
	all->tex->spr = ft_strdup(split[1]);
	free_split(split);
}
