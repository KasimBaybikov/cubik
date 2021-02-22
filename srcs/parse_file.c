/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:29:21 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/22 12:52:55 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_empty(char *line)
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

int		find_key(t_all *all, char *line, t_key *key)
{
	int i;

	i = 0;
	if (key->r && line[i] == 'R' && line[i+1] == ' ')
		get_r(all, line, key); 
	else if (key->no && line[i] == 'N' && line[i+1] == 'O' && line[i+2] == ' ')
		get_no(all, line, key);
	else if (key->so && line[i] == 'S' && line[i+1] == 'O' && line[i+2] == ' ')
		get_so(all, line, key);
	else if (key->we && line[i] == 'W' && line[i+1] == 'E' && line[i+2] == ' ')
		get_we(all, line, key);
	else if (key->ea && line[i] == 'E' && line[i+1] == 'A' && line[i+2] == ' ')
		get_ea(all, line, key);
	else if (key->s && line[i] == 'S' && line[i+1] == ' ')
		get_s(all, line, key);
	else if (key->f && line[i] == 'F' && line[i+1] == ' ')
		get_f(all, line, key);
	else if (key->c && line[i] == 'C' && line[i+1] == ' ')
		get_c(all, line, key);
	else if (key->flag != 8)
		error(3); ///Добавь Чистку
	if (key->flag == 8)
		return (0);
	return (1);
}

void parse_file(t_all *all, int fd)
{
	char *line;
	t_key key;
	char *_free;

	init_key(&key);
	while (get_next_line(fd, &line))
	{
		if (is_empty(line))
			continue;
		_free = line;
		line = ft_strtrim(line, " ");
		free(_free);
		if (find_key(all, line, &key) == 0)
			break ;
		free(line);
	}
	free(line);
}
