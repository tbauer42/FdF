/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:00:06 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/24 18:58:12 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	my_putpixel(t_img *env, int x, int y, int color)
{
	int	pos;
	int	mask;

	if ((x >= 0 && x <= WINX) && (y >= 0 && y <= WINY))
	{
		pos = (y * env->size_line + x * 4);
		mask = color;
		env->pix[pos] = mask;
		color = color >> 8;
		mask = color;
		env->pix[pos + 1] = mask;
		color = color >> 8;
		mask = color;
		env->pix[pos + 2] = mask;
		env->pix[pos + 3] = 0x00;
	}
}

void	trace_segh(t_img *yoz, t_img env, int color)
{
	env.e = env.x2 - env.x1;
	env.dx = env.e * 2;
	env.dy = (env.y2 - env.y1) * 2;
	while (env.x1 <= env.x2)
	{
		my_putpixel(yoz, env.x1, env.y1, color);
		env.x1++;
		env.e = env.e - env.dy;
		if (env.e <= 0)
		{
			env.y1++;
			env.e = env.e + env.dx;
		}
		if (env.e >= 0)
		{
			env.y1--;
			env.e = env.e - env.dx;
		}
	}
}

void	trace_segv(t_img *yoz, t_img env, int color)
{
	env.e = env.y2 - env.y1;
	env.dy = env.e * 2;
	env.dx = (env.x2 - env.x1) * 2;
	while (env.y1 <= env.y2)
	{
		my_putpixel(yoz, env.x1, env.y1, color);
		env.y1++;
		env.e = env.e - env.dx;
		if (env.e <= 0)
		{
			env.x1++;
			env.e = env.e + env.dy;
		}
		if (env.e >= 0)
		{
			env.x1--;
			env.e = env.e - env.dy;
		}
	}
}

void	trace_hori(t_img *env)
{
	env->i = 0;
	env->j = 0;
	env->h = 0;
	while (env->i < env->nb_y)
	{
		env->j = 0;
		env->x1 = 100 + env->h;
		env->y1 = env->base_y - env->tab[env->i][env->j];
		while (env->j < env->nb_x)
		{
			if (env->j + 1 < env->nb_x)
			{
				env->x2 = env->x1 + env->pixel_x;
				env->y2 = env->base_y - env->tab[env->i][env->j + 1];
				env->color = color_trace(env->tab, env->i, env->j, env);
				trace_segh(env, *env, env->color);
				env->x1 = env->x2;
				env->y1 = env->y2;
			}
			env->j++;
		}
		env->h += env->size;
		env->base_y = env->base_y + env->pixel_y;
		env->i++;
	}
}

void	trace_vert(t_img *env)
{
	env->j = 0;
	env->x1 = 100;
	while (env->j < env->nb_x)
	{
		env->i = 0;
		env->base_y = 100;
		env->y1 = env->base_y - env->tab[env->i][env->j];
		while (env->i < env->nb_y)
		{
			if (env->i + 1 < env->nb_y)
			{
				env->x2 = env->x1 + env->size;
				env->y2 = env->pixel_y + env->base_y \
					- env->tab[env->i + 1][env->j];
				env->color = color_trace(env->tab, env->i, env->j, env);
				trace_segv(env, *env, env->color);
				env->x1 = env->x2;
				env->y1 = env->y2;
				env->base_y = env->base_y + env->pixel_y;
			}
			env->i++;
		}
		env->x1 = env->base_x + (env->j + 1) * env->pixel_x;
		env->j++;
	}
}
