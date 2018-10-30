/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:31:36 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 17:31:39 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	d;

	i = 0;
	str = (unsigned char*)s;
	d = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == d)
			return (&(str[i]));
		i++;
	}
	return (NULL);
}
