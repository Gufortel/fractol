/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:20:36 by Gufortel          #+#    #+#             */
/*   Updated: 2019/07/21 18:18:30 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	set_pixel(t_frt *p, int x, int y, int color)
{
	int				bpp;
	int				data;
	unsigned int	clr;
	char			*img;

	clr = mlx_get_color_value(p->mlx, color);
	img = mlx_get_data_addr(p->img, &bpp, &data, &data);
	bpp /= 8;
	if (x < X_MAX && x > 0 && y < Y_MAX && y > 0)
	{
		*(int *)(img + ((x + (y * X_MAX)) * bpp)) = clr;
	}
}
