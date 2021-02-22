/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:42:36 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/22 17:53:56 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_map(t_all *all, t_list *head, int size)
{
	int		i;

	i = -1;
	if (!(all->map = malloc(sizeof(char*) * (size + 1))))
		error(2);
	while (head)
	{
		all->map[++i] = head->content;
		head = head->next;
	}
	all->map[i] = 0;
}

void	parse_map(t_all *all, int fd)
{
	char *line;
	t_list *head;
	int size;

	head = 0;
	size = 0;
	while (get_next_line(fd, &line))
	{
		if (is_empty(line))
			continue ;
		ft_lstadd_back(&head, ft_lstnew(line)); //листы текут
		size++;
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(all, head, size);
	ft_lstclear(&head, 0);
	free(line);
}
