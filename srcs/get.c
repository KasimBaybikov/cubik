/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:01:43 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/20 19:38:43 by rvernon          ###   ########.fr       */
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

void characters_r(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'R' || line[i] == ' ' || (line[i] <= '9' && line[i] >= '0'))
			i++;
		else
			error(3);
	}

}

void	get_r(t_all *all, char *line, t_key *key)
{
	char **split;
	int i;

	key->r = 0;
	i = 0;
	characters_r(line);
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 3)
		error(3);
	//добавь проверку на валидность этих данных
	all->win->w = ft_atoi(split[1]);
	all->win->h = ft_atoi(split[2]);
	free_split(split);
}

void	get_no(t_all *all, char *line, t_key *key)
{
	char **split;
	int i;

	key->no = 0;
	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
		error(3);
	all->tex->no = ft_strdup(split[1]);
	free_split(split);
}

void	get_so(t_all *all, char *line, t_key *key)
{
	char **split;
	int i;

	key->so = 0;
	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
		error(3);
	all->tex->so = ft_strdup(split[1]);
	free(all->tex->so);
	free_split(split);
}

void	get_we(t_all *all, char *line, t_key *key)
{
	char **split;
	int i;

	key->we = 0;
	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
		error(3);
	all->tex->we = ft_strdup(split[1]);
	free(all->tex->we);
	free_split(split);
}

void	get_ea(t_all *all, char *line, t_key *key)
{
	char **split;
	int i;

	key->ea = 0;
	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
		error(3);
	all->tex->ea = ft_strdup(split[1]);
	free_split(split);
}

void	get_s(t_all *all, char *line, t_key *key)
{
	char **split;
	int i;

	key->s = 0;
	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
		error(3);
	all->tex->spr = ft_strdup(split[1]);
	free_split(split);
}


