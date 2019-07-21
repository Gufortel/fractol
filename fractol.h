/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 13:11:00 by Gufortel          #+#    #+#             */
/*   Updated: 2019/07/21 18:19:27 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/includes/libft.h"
# include "./minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define X_MAX 2560
# define Y_MAX 1440

typedef struct		s_frt
{
	void		*mlx;
	void		*win;
	void		*img;
}					t_frt;

t_frt				*createfrt();
void				set_pixel(t_frt *p, int x, int y, int color);

#endif
