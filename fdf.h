/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:11:50 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/26 14:55:38 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/includes/libft.h"
# include <stdlib.h>
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define WINX 2500
# define WINY 1400
# define ESC 53
# define DEZOOM 78
# define ZOOM 69
# define TOP 126
# define BOT 125
# define RIGHT 124
# define LEFT 123

typedef	struct	s_img
{
	int		fd;
	char	*str;
	int		bol;
	char	*av;
	void	*img;
	void	*win;
	void	*mlx;
	void	*adr;
	char	*pix;
	int		endian;
	int		bpp;
	int		img_x;
	int		img_y;
	int		size_line;
	int		i;
	int		j;
	int		h;
	int		max;
	int		min;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;
	int		e;
	int		x;
	int		y;
	int		z;
	int		**tab;
	int		nb_x;
	int		nb_y;
	int		pixel_x;
	int		pixel_y;
	int		size;
	int		base_x;
	int		base_y;
	int		color;
}				t_img;

int				only_nb(char *str);

void			draw(t_img *env);

void			init(t_img *env);

void			echap(int key_num, t_img *env);

int				which_key(int key_num, t_img *env);

void			longueur_line(t_img *env);

void			one_param(int argc);

int				max(t_img *env);

int				color_trace(int **tab, int i, int j, t_img *env);

void			nb_x(t_img *env);

char			*recover_map(char *dst, t_img *env);

int				**recover_coor(int fd, t_img *env);

void			tracer_droite(t_img *env);

void			my_putpixel(t_img *env, int x, int y, int color);

void			trace_hori(t_img *env);

void			trace_vert(t_img *env);

void			trace_segh(t_img *yoz, t_img env, int color);

void			trace_segv(t_img *yoz, t_img env, int color);
#endif
