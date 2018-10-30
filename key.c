/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:23:48 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/26 14:56:23 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dezoum(t_img *env, int i, int j)
{
	env->bol = 0;
	draw(env);
	i = 0;
	while (i < env->nb_y)
	{
		j = 0;
		while (j < env->nb_x)
		{
			if (env->tab[i][j] != 0)
			{
				if (env->tab[i][j] < 0 && (env->tab[i][j] + 1) == 0)
					return ;
				else if (env->tab[i][j] < 0 && (env->tab[i][j] + 1) != 0)
					env->tab[i][j] = env->tab[i][j] + 1;
				else if (env->tab[i][j] > 0 && (env->tab[i][j] - 1) == 0)
					return ;
				else if (env->tab[i][j] > 0 && (env->tab[i][j] - 1) != 0)
					env->tab[i][j] = env->tab[i][j] - 1;
			}
			j++;
		}
		i++;
	}
}

void	zoum(t_img *env, int i, int j)
{
	env->bol = 0;
	draw(env);
	while (i < env->nb_y)
	{
		j = 0;
		while (j < env->nb_x)
		{
			if (env->tab[i][j] != 0)
				env->tab[i][j] = env->tab[i][j] > 0 ? \
					env->tab[i][j] + 1 : env->tab[i][j] - 1;
			j++;
		}
		i++;
	}
}

void	echap(int key_num, t_img *env)
{
	int	i;
	int	j;
	int	maxi;

	i = 0;
	j = 0;
	if (key_num == ESC)
		exit(1);
	else if (key_num == ZOOM)
		zoum(env, i, j);
	else if (key_num == DEZOOM)
		dezoum(env, i, j);
	maxi = max(env);
	env->pixel_x = maxi;
	env->pixel_y = maxi;
}

int		which_key(int key_num, t_img *env)
{
	echap(key_num, env);
	env->bol = 1;
	draw(env);
	return (0);
}
