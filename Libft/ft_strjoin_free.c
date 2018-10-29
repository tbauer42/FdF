/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:45:11 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/29 19:45:40 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char*ft_strjoin_free(char *s1, char *s2, size_t n)
{
	int		i;
	char	*tab;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	if (!(tab = ft_strjoin((const char*)s1, (const char*)s2)))
		return (NULL);
	if (n == 1)
		free(s1);
	if (n == 2)
		free(s2);
	if (n == 3)
	{
		free(s2);
		free(s1);
	}
	return (tab);
}
