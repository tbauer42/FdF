/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:37:32 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 17:37:34 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = ft_strlen(dest);
	str = (char*)dest;
	while (i < n)
	{
		str[j + i] = src[i];
		i++;
	}
	str[j + i] = '\0';
	return (str);
}
