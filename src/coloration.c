/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloration.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 07:16:41 by moseddik          #+#    #+#             */
/*   Updated: 2022/01/21 18:40:36 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_coloration(t_data *data)
{
	data->frequenc = 0.5;
}

void	coloration(t_data *data)
{
	data->bright = data->iteration + 1 - (log(2)
			/ (data->a * data->a + data->b * data->b)) / log (2);
	data->pixel = (data->x + data->y * WINDOW_WIDTH) * 4;
	if (data->iteration == data->maxiterations)
	{
		data->addr[data->pixel + 0] = 0;
		data->addr[data->pixel + 1] = 0;
		data->addr[data->pixel + 2] = 0;
	}
	else
	{
		data->addr[data->pixel + 0] = (unsigned char)
			(sin(0.77 * data->frequenc * data->bright / data->maxiterations)
				* 230);
		data->addr[data->pixel + 1] = (unsigned char)
			(sin(0.89 * data->frequenc * data->bright / data->maxiterations)
				* 230);
		data->addr[data->pixel + 2] = (unsigned char)
			(sin(1.99 * data->frequenc * data->bright / data->maxiterations)
				* 230);
	}
}
