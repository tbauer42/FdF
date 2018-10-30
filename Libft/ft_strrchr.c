/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:38:44 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 17:38:49 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*pntr;

	i = ft_strlen(s);
	pntr = (char*)s;
	while (i >= 0)
	{
		if (pntr[i] == c)
			return (&pntr[i]);
		i--;
	}
	return (NULL);
}
