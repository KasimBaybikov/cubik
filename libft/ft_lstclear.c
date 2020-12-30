/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:35:41 by rvernon           #+#    #+#             */
/*   Updated: 2020/11/21 23:10:09 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *plist;
	t_list *ptmp;

	if (!*lst)
		return ;
	plist = *lst;
	ptmp = *lst;
	while (plist)
	{
		del(plist->content);
		ptmp = plist->next;
		free(plist);
		plist = ptmp;
	}
	*lst = NULL;
}
