/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:04:03 by moseddik          #+#    #+#             */
/*   Updated: 2022/01/21 18:43:17 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	julia_init(t_data *data)
{
	data->julia_var_re = 0.285;
	data->julia_var_im = 0.01;
}

void	calcul_iter_julia(t_data *data)
{
	data->iteration = 0;
	while (data->iteration < data->maxiterations)
	{
		data->aa = (data->a * data->a) - (data->b * data->b);
		data->bb = 2 * data->a * data->b;
		data->a = data->aa + data->julia_var_re;
		data->b = data->bb + data->julia_var_im;
		if ((data->a * data->a + data->b * data->b) > 4)
			break ;
		data->iteration++;
	}
}

void	julia(t_data *data)
{
	data->y = 0;
	while (data->y < WINDOW_HEIGHT)
	{
		data->x = 0;
		while (data->x < WINDOW_WIDTH)
		{
			data->a = (data->x * data->x_scale) - data->x_center;
			data->b = (data->y * data->y_scale) - data->y_center;
			data->c_re = data->a;
			data->c_im = data->b;
			calcul_iter_julia(data);
			coloration(data);
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
