/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 13:13:53 by Gufortel          #+#    #+#             */
/*   Updated: 2019/07/21 18:19:20 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

t_frt	*createfrt()
{
	t_frt	*ptr;

	ptr = (t_frt*)ft_memalloc(sizeof(t_frt));
	if (!ptr)
	{
		ft_printf("Wrong Malloc");
		exit(-1);
	}
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, X_MAX, Y_MAX, "Fdf");
	return (ptr);
}
