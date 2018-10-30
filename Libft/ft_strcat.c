/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:34:07 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 17:34:09 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		j;
	char	*src1;

	i = 0;
	j = ft_strlen(dest);
	src1 = (char*)src;
	while (src1[i] != '\0')
	{
		dest[j + i] = src1[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}
