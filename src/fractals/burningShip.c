/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningShip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:02:27 by moseddik          #+#    #+#             */
/*   Updated: 2022/01/21 18:43:01 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	calcul_iter_burningship(t_data *data)
{
	data->iteration = 0;
	while (data->iteration < data->maxiterations)
	{
		data->aa = data->a * data->a - data->b * data->b;
		data->bb = 2 * data->a * data->b;
		data->a = data->aa + data->c_re;
		data->b = data->bb + data->c_im;
		if (data->a < 0)
			data->a *= -1;
		if (data->b < 0)
			data->b *= -1;
		if ((data->a * data->a + data->b * data->b) > 4)
			break ;
		data->iteration++;
	}
}

void	burningship(t_data *data)
{
	data->y = 0;
	while (data->y < WINDOW_HEIGHT)
	{
		data->x = 0;
		while (data->x < WINDOW_WIDTH)
		{
			data->a = 0;
			data->b = 0;
			data->c_re = (data->x * data->x_scale) - data->x_center;
			data->c_im = (data->y * data->y_scale) - data->y_center;
			calcul_iter_burningship(data);
			coloration(data);
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
