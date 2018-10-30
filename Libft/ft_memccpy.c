/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:31:28 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 17:31:30 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dest1;
	char	*src1;

	i = 0;
	dest1 = (char*)dest;
	src1 = (char*)src;
	while (i < n)
	{
		dest1[i] = src1[i];
		if (dest1[i] == c)
		{
			i++;
			return (&dest[i]);
		}
		i++;
	}
	return (NULL);
}
