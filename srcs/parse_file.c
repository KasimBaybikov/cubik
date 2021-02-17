/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:29:21 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/17 14:43:32 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *find_key(char *line)
{
	(void)line;
	int i;

	i = 0;
	return (line);
}

void parse_file(t_all *all, int fd)
{
	char *line;
	char *key;

	(void)all;
	while (get_next_line(fd, &line))
	{
		key = find_key(line);
		printf("%s", key);
	}
}
