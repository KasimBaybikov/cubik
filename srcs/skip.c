/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:12:20 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/06 20:15:57 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char*		skip_spaces(char *s)
{
	while (*s == ' ')
		s++;
	return (s);
}

char*		skip_dots(char *s)
{
	while (*s == ',')
		s++;
	return (s);
}

char*		skip_numbers(char *s)
{
	while (*s >= '0' && *s <= '9')
		s++;
	return (s);
}
