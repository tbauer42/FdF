/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:30:40 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 17:30:41 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *nxt;

	if (lst != NULL || f != NULL)
	{
		while (lst)
		{
			nxt = lst->next;
			f(lst);
			lst = nxt;
		}
	}
}
