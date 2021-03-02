/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:01:43 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/02 14:17:28 by rvernon          ###   ########.fr       */
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

void characters_r(char *line, t_all *all)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'R' || line[i] == ' ' || (line[i] <= '9' && line[i] >= '0'))
			i++;
		else
			error(3, all);
	}

}

void	get_r(t_all *all, char *line, t_key *key)
{
	char **split;
	int i;

	key->r = 0;
	key->flag++;
	i = 0;
	characters_r(line, all);
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 3)
		error(3, all);
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
	char **split;
	int i;

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
	char **split;
	int i;

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
	char **split;
	int i;

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
	char **split;
	int i;

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
