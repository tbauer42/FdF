/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:32:23 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 17:32:30 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*temp;
	char	*dest1;
	char	*src1;

	i = 0;
	dest1 = (char*)dest;
	src1 = (char*)src;
	temp = ((char*)malloc(sizeof(temp) * (n + 1)));
	if (temp == NULL)
		return (NULL);
	while (n > i)
	{
		temp[i] = src1[i];
		i++;
	}
	i = 0;
	while (n > i)
	{
		dest1[i] = temp[i];
		i++;
	}
	free(temp);
	return (dest1);
}
