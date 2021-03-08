/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:26:57 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/03/08 13:07:40 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(int error, t_all *all)
{
	if (error == 0)
		printf("\033[32mContinue\n\033[0m");
	else if (error == 1)
		printf("\033[31mERROR:\ninvalid file name\n\033[0m");
	else if (error == 2)
		printf("\033[31mERROR:\nfile cannot be opened\n\033[0m");
	else if (error == 3)
		printf("\033[31mERROR:\ninvalid argument\n\033[0m");
	else if (error == 4)
		printf("\033[31mERROR:\ninvalid map\n\033[0m");
	else if (error == 5)
		printf("\033[31mERROR:\ninvalid texture\n\033[0m");
	free_all(all);
	exit(1);
}
