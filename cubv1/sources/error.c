/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasimbaybikov <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:19:31 by kasimbayb         #+#    #+#             */
/*   Updated: 2021/02/11 13:12:31 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/*
 * it cool function
*/
void	ft_error(int error)
{
	if (error == 1)
		ft_printf("\033[31mERROR: invalid file name\033[0m");
	else if (error == 2)
		ft_printf("\033[31mERROR: the file cannot be opened\033[0m");
	else if (error == 3)
		ft_printf("\033[31mERROR: invalid map\033[0m");
	else if (error == 4)
		ft_printf("\033[31mERROR: AAAAAAAAAAAAa\033[0m");
}
