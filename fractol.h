/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 13:11:00 by Gufortel          #+#    #+#             */
/*   Updated: 2019/07/27 20:28:35 by Gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/includes/libft.h"
# include "./minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define X_MAX 1680
# define Y_MAX 1000

typedef struct		s_frt
{
	void			*mlx;
	void			*win;
	void			*img;
	int				x;
	int				y;
	int				i;
	int				max_i;
	int				**tab;
	long double		x1;
	long double		x2;
	long double		y1;
	long double		y2;
	long double		cr;
	long double		ci;
	long double		zr;
	long double		zi;
	long double		tmp;
	long double		zoom_x;
	long double		zoom_y;
}					t_frt;

t_frt				*createfrt();
void				set_pixel(t_frt *p, int x, int y, int color);

#endif
