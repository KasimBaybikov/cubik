/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:42:36 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/05 14:22:40 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill(t_all *all, int x, int y, char new)
{
	if (x < 0 || y < 0 || x >= all->map_w || y >= all->map_h || all->map[y][x] == ' ' || all->map[y][x] == 0)
		error(4, all);
	if (all->map[y][x] != new && all->map[y][x] != ' ' && all->map[y][x] != '1' && all->map[y][x] != 0)
	{
		all->map[y][x] = new;
		flood_fill(all, x, y - 1, new);
		flood_fill(all, x, y + 1, new);
		flood_fill(all, x + 1, y, new);
		flood_fill(all, x - 1, y, new);
		flood_fill(all, x + 1, y + 1, new);
		flood_fill(all, x - 1, y - 1, new);
		flood_fill(all, x - 1, y + 1, new);
		flood_fill(all, x + 1, y - 1, new);
	}
}

void	filled_map(char **map, char **fill_map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			fill_map[i][j] = map[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}

void	free_fill(char **fill_map)
{
	int i;

	i = 0;
	while (fill_map[i])
		free(fill_map[i++]);
	free(fill_map);
	fill_map = 0;
}

void	make_fill(t_all *all)
{
	int i;
	char **fill_map;

	fill_map = 0;

	i = 0;
	if (!(fill_map = malloc(sizeof(char *) * (all->map_h + 1))))
		error(4, all);
	while (i < all->map_h)
	{
		fill_map[i] = malloc(sizeof(char) * all->map_w + 1);
		ft_memset(fill_map[i], ' ', all->map_w);
		fill_map[i][all->map_w] = 0;
		i++;
	}
	fill_map[i] = 0;
	filled_map(all->map, fill_map);
	flood_fill(all, all->plr->x, all->plr->y, 6);
	free_fill(fill_map);
}

void	make_map(t_all *all, t_list *head, int size)
{
	int		i;

	i = -1;
	if (!(all->map = malloc(sizeof(char*) * (size + 1))))
		error(2, all);
	while (head)
	{
		all->map[++i] = head->content;
		head = head->next;
	}
	all->map[i] = 0;
	i = 0;
	while (all->map[i])
	{
		all->map_w = ((int)ft_strlen(all->map[i]) > all->map_w) ? (int)ft_strlen(all->map[i]) : all->map_w;
		i++;
	}
	if (get_pos_plr(all) != 1)
		error(4, all);
	get_sprites(all, 0 , 0, 0);
	make_fill(all);
}

void	parse_map(t_all *all, int fd)
{
	char *line;
	t_list *head;

	head = 0;
	while (get_next_line(fd, &line))
	{
		if (is_empty(line))
			continue ;
		if (!valid_line(line))
			error(4, all);
		ft_lstadd_back(&head, ft_lstnew(line)); //листы текут
		all->map_h++;
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(all, head, all->map_h);
	ft_lstclear(&head, 0);
	free(line);
}
