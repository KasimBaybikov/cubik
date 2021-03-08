/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:52:42 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/08 14:33:31 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_header(t_all *all, int fd)
{
	char	*head;
	int		i;
	int		size_bmp;

	i = 0;
	size_bmp = all->win->h * (all->win->w * all->img->bpp / 8) + 54;
	head = malloc(sizeof(char) * 14);
	while (i < 14)
		head[i++] = 0;
	head[0] = 'B';
	head[1] = 'M';
	head[2] = size_bmp;
	head[3] = size_bmp >> 8;
	head[4] = size_bmp >> 16;
	head[5] = size_bmp >> 24;
	head[10] = 54;
	write(fd, head, 14);
	free(head);
}

void	get_bmp(t_all *all, int fd)
{
	int		i;
	char	*bmp;

	i = 0;
	bmp = malloc(sizeof(char) * 40);
	while (i < 40)
		bmp[i++] = 0;
	bmp[0] = 40;
	bmp[4] = all->win->w;
	bmp[5] = all->win->w >> 8;
	bmp[6] = all->win->w >> 16;
	bmp[7] = all->win->w >> 24;
	bmp[8] = all->win->h;
	bmp[9] = all->win->h >> 8;
	bmp[10] = all->win->h >> 16;
	bmp[11] = all->win->h >> 24;
	bmp[12] = 1;
	bmp[14] = all->img->bpp;
	write(fd, bmp, 40);
	free(bmp);
}

void	write_img(t_all *all, int fd)
{
	int i;
	int j;

	i = all->win->h - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < all->win->w)
		{
			write(fd, all->img->addr + (j * all->img->bpp / 8) +
					(i * all->img->line_len), all->img->bpp / 8);
			j++;
		}
		i--;
	}
}

void	screen(t_all *all, char *str)
{
	int fd;
	int i;

	i = 0;
	all->screen = 1;
	start(str, all);
	if ((fd = open("screen.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0777)) < 0)
		error(0, all);
	get_header(all, fd);
	get_bmp(all, fd);
	write_img(all, fd);
	free_all(all);
	return ;
}
