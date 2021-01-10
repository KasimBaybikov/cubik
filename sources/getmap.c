/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:58:21 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/01/10 14:55:08 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_map(t_all *all)
{
	char	**map;
	int		i;
	int		j;

	i = -1;
	j = -1;
	map = all->map;

	return (1);
}

void	get_map(int size, t_list *lstmap, t_all *all)
{
	int i;

	i = -1;
	if (!(all->map = malloc(sizeof(char*) * (size + 1))))
		ft_error(3);
	while (lstmap)
	{
		all->map[++i] = lstmap->content;
		lstmap = lstmap->next;
	}
	all->map[i] = NULL;
	/*i = -1; //вывод массива карты
	int j = -1;
	while (map[++i])
	{
		while (map[i][++j])
			ft_printf("%c", map[i][j]);
		j = -1;
		ft_printf("\n");
	}*/
	//на руках есть карта, начинай римовать;
	if (check_map(all))
		draw_map(all);
	else
		ft_error(3);
}

void	get_lstmap(int fd, t_all *all)
{
	char	*line = NULL;
	t_list *lstmap = NULL;
	int size = 0;

	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&lstmap, ft_lstnew(line));
		size++;
	}
	ft_lstadd_back(&lstmap, ft_lstnew(line));
	/*while (lstmap) //вывод списка
	{
		ft_printf("%s\n", lstmap->content);
		lstmap = lstmap->next;
	}*/
	get_map(size, lstmap, all);
}
