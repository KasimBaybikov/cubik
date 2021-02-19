/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:29:21 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/19 20:48:20 by rvernon          ###   ########.fr       */
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
	return (1);
}

void	find_key(t_all *all, char *line)
{
	int i;

	i = 0;
	if (line[i] == 'R' && line[i+1] == ' ')
		get_r(all, line);
	else if (line[i] == 'N' && line[i+1] == 'O' && line[i+2] == ' ')
		get_no(all, line);
	else if (line[i] == 'S' && line[i+1] == 'O' && line[i+2] == ' ')
		get_so(all, line);
	else if (line[i] == 'W' && line[i+1] == 'E' && line[i+2] == ' ')
		get_we(all, line);
	else if (line[i] == 'E' && line[i+1] == 'A' && line[i+2] == ' ')
		get_ea(all, line);
	else if (line[i] == 'S' && line[i+1] == ' ')
		get_s(all, line);
	else if (line[i] == 'F' && line[i+1] == ' ')
		get_f(all, line);
	else if (line[i] == 'F' && line[i+1] == ' ')
		get_s(all, line);
	else
	{
		error(4); ///Добавь Чистку
		exit(1);
	}


}

void parse_file(t_all *all, int fd)
{
	char *line;

	while (get_next_line(fd, &line))
	{
		if (is_empty(line))
			continue;
		line = ft_strtrim(line, " ");
		//printf(".%s\n", line);
		find_key(all, line);
		free(line);

	}
}
