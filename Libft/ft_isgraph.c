/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:29:07 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 17:29:09 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isgraph(int c)
{
	if (c > 32 && c < 127)
		return (1);
	else
		return (0);
}
