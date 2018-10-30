/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:35:26 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 17:08:48 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/includes/libft.h"
#include "fdf.h"
#include <stdlib.h>

void	one_param(int argc)
{
	if (argc != 2)
		exit(1);
}

void	longueur_line(t_img *env)
{
	char	*line;
	int		i;
	int		fd;
	char	**tab;

	fd = open(env->av, O_RDONLY);
	if (fd < 0)
		return ;
	while ((env->j = get_next_line(fd, &line)) > 0)
	{
		i = 0;
		tab = ft_strsplit(line, ' ');
		while (tab[i])
			i++;
		if (i != env->nb_x)
			exit(1);
		i = -1;
		while (tab[++i])
			free(tab[i]);
		free(tab);
		free(line);
	}
	if (env->j == 0)
		free(line);
	close(fd);
}

void	init(t_img *env)
{
	env->base_y = 100;
	env->base_x = 100;
	env->img_x = WINX;
	env->img_y = WINY;
}

void	draw(t_img *env)
{
	init(env);
	trace_hori(env);
	trace_vert(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

int		only_nb(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || \
					str[i] == '\n' || str[i] == '-'))
			exit(1);
		i++;
	}
	return (0);
}
