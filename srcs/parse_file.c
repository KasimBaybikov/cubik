/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:29:21 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/08 13:51:55 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			is_empty(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	free(line);
	return (1);
}

int			find_key(t_all *all, char *l, t_key *key)
{
	int i;

	i = 0;
	if (key->r && l[i] == 'R' && l[i + 1] == ' ')
		get_r(all, l, key);
	else if (key->no && l[i] == 'N' && l[i + 1] == 'O' && l[i + 2] == ' ')
		get_no(all, l, key);
	else if (key->so && l[i] == 'S' && l[i + 1] == 'O' && l[i + 2] == ' ')
		get_so(all, l, key);
	else if (key->we && l[i] == 'W' && l[i + 1] == 'E' && l[i + 2] == ' ')
		get_we(all, l, key);
	else if (key->ea && l[i] == 'E' && l[i + 1] == 'A' && l[i + 2] == ' ')
		get_ea(all, l, key);
	else if (key->s && l[i] == 'S' && l[i + 1] == ' ')
		get_s(all, l, key);
	else if (key->f && l[i] == 'F' && l[i + 1] == ' ')
		get_f(all, l, key);
	else if (key->c && l[i] == 'C' && l[i + 1] == ' ')
		get_c(all, l, key);
	else if (key->flag != 8)
		error(3, all);
	if (key->flag == 8)
		return (0);
	return (1);
}

void		parse_file(t_all *all, int fd)
{
	char	*line;
	t_key	key;
	char	*my_free;

	init_key(&key);
	while (get_next_line(fd, &line))
	{
		if (is_empty(line))
			continue;
		my_free = line;
		line = ft_strtrim(line, " ");
		free(my_free);
		if (find_key(all, line, &key) == 0)
			break ;
		free(line);
	}
	free(line);
}
