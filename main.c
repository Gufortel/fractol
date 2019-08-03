/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:09:27 by Gufortel          #+#    #+#             */
/*   Updated: 2019/07/27 20:32:58 by Gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void 	init_mandelbrot(t_frt *p)
{
	int i;

	i = 0;
	p->x1 = -2.1;
	p->x2 = 0.6;
	p->y1 = -1.2;
	p->y2 = 1.2;
	p->max_i = 100;
	p->tab = (int**)ft_memalloc(sizeof(int*) * X_MAX);
	while (i < X_MAX)
	{
		p->tab[i] = (int*)ft_memalloc(sizeof(int) * Y_MAX);
		i++;
	}
}

void	create_fractol_mandelbrot(t_frt *p)
{
	if (p->max_i == 0)
		init_mandelbrot(p);
	p->img = mlx_new_image(p->mlx, X_MAX, Y_MAX);
	p->zoom_x = X_MAX/(p->x2 - p->x1);
	p->zoom_y = Y_MAX/(p->y2 - p->y1);
	p->x = 0;
	while (p->x < X_MAX)
	{
		p->y = 0;
		while (p->y < Y_MAX)
		{
			p->cr = p->x / p->zoom_x + p->x1;
			p->ci = p->y / p->zoom_y + p->y1;
			p->zr = 0;
			p->zi = 0;
			p->i = 0;
			while (p->i == 0 || (p->zr * p->zr + p->zi * p->zi < 4 && p->i < p->max_i))
			{
				p->tmp = p->zr;
				p->zr = pow(p->zr, 2) - pow(p->zi, 2) + p->cr;
				p->zi = 2 * p->zi * p->tmp + p->ci;
				p->i = p->i + 1;
			}
			if (p->i == p->max_i)
				set_pixel(p, p->x, p->y, 255);
			else
				set_pixel(p, p->x, p->y, p->i * 16777215 / p->max_i);
			p->y = p->y + 1;
		}
		p->x = p->x + 1;
	}
	mlx_clear_window(p->mlx, p->win);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

void	init_julia(t_frt *p)
{
	p->x1 = -1;
	p->x2 = 1;
	p->y1 = -1.2;
	p->y2 = 1.2;
	p->max_i = 150;
	
}

void	create_fractol_julia(t_frt *p)
{
	int i;

	char buffer[50];
	if (p->max_i == 0)
		init_julia(p);
	p->img = mlx_new_image(p->mlx, X_MAX, Y_MAX);
	i = 0;
	p->zoom_x = X_MAX/(p->x2 - p->x1);
	p->zoom_y = Y_MAX/(p->y2 - p->y1);
	p->x = 0;
	while (p->x < X_MAX)
	{
		p->y = 0;
		while (p->y < Y_MAX)
		{
			p->cr = 0.285;
			p->ci = 0.01;
			p->zr = p->x / p->zoom_x + p->x1;
			p->zi = p->y / p->zoom_y + p->y1;
			i = 0;
			while (i == 0 || (p->zr * p->zr + p->zi * p->zi < 4 && i < p->max_i))
			{
				p->tmp = p->zr;
				p->zr = p->zr * p->zr - p->zi * p->zi + p->cr;
				p->zi = 2 * p->zi * p->tmp + p->ci;
				i++;
			}
			if (i == p->max_i)
				set_pixel(p, p->x, p->y, 255);
			else
				set_pixel(p, p->x, p->y, i * (16777215 * 1) / p->max_i);
			p->y = p->y + 1;
		}
		p->x = p->x + 1;
	}
	mlx_clear_window(p->mlx, p->win);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	sprintf(buffer, "p->x1 = %Lf:", p->x1);
	mlx_string_put(p->mlx, p->win, 10, 10, 16711680, buffer);
	sprintf(buffer, "p->x2 = %Lf", p->x2);
	mlx_string_put(p->mlx, p->win, 10, 30, 16711680, buffer);
	sprintf(buffer, "p->y1 = %Lf", p->y1);
	mlx_string_put(p->mlx, p->win, 10, 50, 16711680, buffer);
	sprintf(buffer, "p->y2 = %Lf", p->y2);
	mlx_string_put(p->mlx, p->win, 10, 70, 16711680, buffer);
	sprintf(buffer, "p->max_i = %d", p->max_i);
	mlx_string_put(p->mlx, p->win, 10, 90, 16711680, buffer);
}

void	create_fractol_budha(t_frt *p)
{
	int i;

	char buffer[50];
	if (p->max_i == 0)
		init_mandelbrot(p);
	i = -1;
	while (++i < X_MAX)
		ft_bzero(p->tab[i], Y_MAX * 4);
	p->img = mlx_new_image(p->mlx, X_MAX, Y_MAX);
	i = 0;
	p->zoom_x = X_MAX/(p->x2 - p->x1);
	p->zoom_y = Y_MAX/(p->y2 - p->y1);
	p->x = 0;
	while (p->x < X_MAX)
	{
		p->y = 0;
		while (p->y < Y_MAX)
		{
			p->cr = p->x / p->zoom_x + p->x1;
			p->ci = p->y / p->zoom_y + p->y1;
			p->zr = 0;
			p->zi = 0;
			i = 0;
			while (i == 0 || (p->zr * p->zr + p->zi * p->zi < 4 && i < p->max_i))
			{
				p->tmp = p->zr;
				p->zr = pow(p->zr, 2) - pow(p->zi, 2) + p->cr;
				p->zi = 2 * p->zi * p->tmp + p->ci;
				i++;
			}
			if (i != p->max_i)
			{
			p->cr = p->x / p->zoom_x + p->x1;
			p->ci = p->y / p->zoom_y + p->y1;
			p->zr = 0;
			p->zi = 0;
			i = 0;
//	ft_printf("ici\n");
			while (i == 0 || (p->zr * p->zr + p->zi * p->zi < 4 && i < p->max_i))
			{
				p->tmp = p->zr;
				p->zr = pow(p->zr, 2) - pow(p->zi, 2) + p->cr;
				p->zi = 2 * p->zi * p->tmp + p->ci;
				i++;
				if ((int)((p->zr - p->x1) * p->zoom_x) < X_MAX
				&& (int)((p->zr - p->x1) * p->zoom_x) >= 0
				&& (int)((p->zi - p->y1) * p->zoom_y) < Y_MAX
				&& (int)((p->zi - p->y1) * p->zoom_y) >= 0)
				{
					//ft_printf("value = %d\n", p->tab[(int)((p->zr - p->x1) * p->zoom_x)][(int)((p->zi - p->y1) * p->zoom_y)]);
					p->tab[(int)((p->zr - p->x1) * p->zoom_x)][(int)((p->zi - p->y1) * p->zoom_y)] =
					p->tab[(int)((p->zr - p->x1) * p->zoom_x)][(int)((p->zi - p->y1) * p->zoom_y)] + 1;
				}
			}
			}
			p->y = p->y + 1;
		}
		p->x = p->x + 1;
	}
	p->x = 0;
	while(p->x < X_MAX)
	{
		p->y = 0;
		while(p->y < Y_MAX)
		{
			set_pixel(p, p->x, p->y, p->tab[p->x][p->y] * 16777215);
			p->y = p->y + 1;
		}
		p->x = p->x + 1;
	}
	mlx_clear_window(p->mlx, p->win);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	sprintf(buffer, "p->x1 = %Lf:", p->x1);
	mlx_string_put(p->mlx, p->win, 10, 10, 16711680, buffer);
	sprintf(buffer, "p->x2 = %Lf", p->x2);
	mlx_string_put(p->mlx, p->win, 10, 30, 16711680, buffer);
	sprintf(buffer, "p->y1 = %Lf", p->y1);
	mlx_string_put(p->mlx, p->win, 10, 50, 16711680, buffer);
	sprintf(buffer, "p->y2 = %Lf", p->y2);
	mlx_string_put(p->mlx, p->win, 10, 70, 16711680, buffer);
	sprintf(buffer, "p->max_i = %d", p->max_i);
	mlx_string_put(p->mlx, p->win, 10, 90, 16711680, buffer);
}

int		key_hook(int keycode, void *params)
{
	t_frt *p;

	p = params;
		long double i = (p->x2 - p->x1) * 0.1;
		long double j = (p->y2 - p->y1) * 0.1;
	ft_printf("keycode = %d\ni = %Lf\n", keycode, i);
	if (keycode == 43)
	{
		p->x1 += i;
		p->x2 -= i;
		p->y1 += j;
		p->y2 -= j;
	}
	else if (keycode == 47)
	{
		p->x1 -= i;
		p->x2 += i;
		p->y1 -= j;
		p->y2 += j;
	}
	else if (keycode == 123)
	{
		p->x1 -= i;
		p->x2 -= i;
	}
	else if (keycode == 124)
	{
		p->x1 += i;
		p->x2 += i;
	}
	else if (keycode == 126)
	{
		p->y1 -= j;
		p->y2 -= j;
	}
	else if (keycode == 125)
	{
		p->y1 += j;
		p->y2 += j;
	}
	else if (keycode == 19)
	{
		p->max_i += 10;
	}
	else if (keycode == 18)
	{
		p->max_i -= 10;
	}
	else if (keycode == 53)
		exit(42);
	create_fractol_mandelbrot(p);
	return (1);
}

int		main(int ac, char **av)
{
	t_frt *p;
	av = av + 0;
	if (ac != 2)
	{
		ft_printf("Bad number argument\n");
		return (-1);
	}
	p = createfrt();
	create_fractol_mandelbrot(p);
	//create_fractol_julia(p);
	//create_fractol_budha(p);
	mlx_key_hook(p->win, key_hook, p);
	mlx_loop(p->mlx);
	return (0);
}