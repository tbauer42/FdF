/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:21:11 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 17:24:18 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/includes/libft.h"
#include "fdf.h"
#include <stdlib.h>

char	*recover_map(char *dst, t_img *pt)
{
	pt->nb_x = 0;
	pt->nb_y = 0;
	pt->fd = open(pt->av, O_RDONLY);
	if (!(pt->map = malloc(sizeof(char))))
		return (NULL);
	pt->map[0] = '\0';
	while ((pt->i = get_next_line(pt->fd, &(pt->line))) > 0)
	{
		if (pt->map == NULL)
			pt->map = ft_strdup(pt->line);
		else
		{
			pt->tmp = pt->map;
			pt->map = ft_strjoin(pt->tmp, pt->line);
			ft_strdel(&(pt->tmp));
			pt->nb_y++;
		}
		free(pt->line);
	}
	if (pt->i == 0)
		free(pt->line);
	if (pt->i == -1)
		exit(1);
	close(pt->fd);
	return (pt->map);
}

int		color_trace(int **tab, int i, int j, t_img *env)
{
	int	k;

	k = 0;
	if (env->bol == 1)
	{
		if (tab[i][j] > 0)
			k = 0x33FF5E;
		else if (tab[i][j] < 0)
			k = 0xFF8633;
		else
			k = 0x3C33FF;
	}
	else
		k = 0x000000;
	return (k);
}

void	nb_x(t_img *pt)
{
	int		i;
	int		fd;
	char	*line;
	char	**tab;

	i = 0;
	fd = open(pt->av, O_RDONLY);
	if (fd < 0)
		return ;
	get_next_line(fd, &line);
	tab = ft_strsplit(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
		free(line);
	free(line);
	while (tab[i])
		i++;
	pt->nb_x = i;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	close(fd);
}

int		**recover_coor(int fd, t_img *env)
{
	env->i = 0;
	fd = open(env->av, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!(env->tab = (int**)malloc(sizeof(int*) * env->nb_y)))
		return (NULL);
	while (env->i < env->nb_y)
	{
		env->j = -1;
		get_next_line(fd, &(env->line));
		env->dst = ft_strsplit(env->line, ' ');
		env->tab[env->i] = (int*)malloc(sizeof(int) * (env->nb_x));
		while (env->dst[++(env->j)])
			env->tab[env->i][env->j] = ft_atoi(env->dst[env->j]);
		env->k = -1;
		while (env->dst[++(env->k)])
			free(env->dst[env->k]);
		free(env->dst);
		free(env->line);
		env->i++;
	}
	close(fd);
	return (env->tab);
}

int		max(t_img *env)
{
	env->max = 0;
	env->min = 0;
	env->i = 0;
	while (env->i < env->nb_y)
	{
		env->j = 0;
		while (env->j < env->nb_x)
		{
			if (env->tab[env->i][env->j] < 0)
			{
				if (env->tab[env->i][env->j] * -1 > env->min)
					env->min = env->tab[env->i][env->j] * -1;
			}
			else if (env->tab[env->i][env->j] > env->max)
				env->max = env->tab[env->i][env->j];
			env->j++;
		}
		env->i++;
	}
	if (env->max == 0)
		env->max = 10;
	else
		env->max += env->min;
	return (env->max);
}
