/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:58:34 by rvernon           #+#    #+#             */
/*   Updated: 2020/12/13 14:10:21 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		numlen(long n)
{
	long len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa(long n)
{
	char	*nbr;
	int		count;
	int		sign;

	count = numlen(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	if (!(nbr = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	nbr[count] = '\0';
	count--;
	{
		while (count >= 0)
		{
			nbr[count] = ((n % 10) * sign) + '0';
			n = n / 10;
			count--;
		}
	}
	return (nbr);
}
