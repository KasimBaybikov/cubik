/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:18:30 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/01/04 01:55:12 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int pos_player(char **map, int i, int j)
{
	if (map[i][j] == 'N')
		return (1);
	else if (map[i][j] == 'W')
		return (2);
	else if (map[i][j] == 'S')
		return (3);
	else if (map[i][j] == 'E')
		return (4);
	return (0);
}

void draw_pix(t_win *window, char **map, int i, int j, int color)
{
	int x;
	int y;

	x = -1;
	y = -1;
	(void)map;
	while (++x < 20)
	{
		while (++y < 20)
		{		
			mlx_pixel_put(window->mlx, window->win, i + x, j + y, color);
		}
		y = -1;
	}
}

void	draw_map(char **map)
{
	int i;
	int j;
	t_win window;

	i = -1;
	j = -1;
	init_window(&window);
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 800, 600, "Cub3D");
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				draw_pix(&window, map, j*20, i * 20, get_trgb(0, 255, 150, 200));
			if (pos_player(map, i, j))
				draw_pix(&window, map, j*20, i * 20, get_trgb(0, 10, 20, 200));
		}
		j = -1;
	}
	mlx_loop(window.mlx);

}

void	get_map(int size, t_list *lstmap)
{
	char **map;
	int i;

	i = -1;
	if (!(map = malloc(sizeof(char*) * (size + 1))))
		ft_error(3);
	while (lstmap)
	{
		map[++i] = lstmap->content;
		lstmap = lstmap->next;
	}
	map[i] = NULL;
	/*i = -1; //вывод массива карты
	int j = -1;
	while (map[++i])
	{
		while (map[i][++j])
			ft_printf("%c", map[i][j]);
		j = -1;
		ft_printf("\n");
	}*/
	draw_map(map);
}

void	get_lstmap(int fd)
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
	get_map(size, lstmap);
}

void	get_params(char *map)
{
	int		fd;

	char *line;
		fd = 0;
	if ((fd = open(map, O_RDONLY)) == -1)
		return (ft_error(2));
	get_next_line(fd, &line);
	get_lstmap(fd);
}

int		check_map_name(char *name)
{
	int i;

	i = -1;
	while (name && *name && *name != '.')
		name++;
	if (*name == '.')
		name++;
	if (ft_strcmp(name, "cub") == 0)
		return (1);
	else
		ft_error(1);
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 1)
		ft_error(1);
	else if (argc == 2 && check_map_name(argv[1]) == 1)
	{
		get_params(argv[1]);
	}
	return (0);
}
