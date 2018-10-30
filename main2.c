/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 13:58:49 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 17:08:57 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		maxi;
	t_img	env;

	env.str = NULL;
	one_param(argc);
	init(&env);
	env.av = argv[1];
	env.bol = 1;
	env.mlx = mlx_init();
	env.img = mlx_new_image(env.mlx, env.img_x, env.img_y);
	env.win = mlx_new_window(env.mlx, WINX, WINY, "FdF");
	env.pix = mlx_get_data_addr(env.img, &env.bpp, &env.size_line, &env.endian);
	env.str = recover_map(env.str, &env);
	only_nb(env.str);
	nb_x(&env);
	env.tab = recover_coor(env.fd, &env);
	longueur_line(&env);
	maxi = max(&env);
	env.pixel_x = maxi;
	env.pixel_y = maxi;
	env.size = 5;
	draw(&env);
	mlx_key_hook(env.win, which_key, &env);
	mlx_loop(env.mlx);
	return (0);
}
