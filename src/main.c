/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:18:56 by moseddik          #+#    #+#             */
/*   Updated: 2022/01/21 18:52:56 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	fract_comp(char *name_of_fract, t_data *data)
{
	init_coloration(data);
	if (ft_strcmp(name_of_fract, "mandelbrot") == 0)
		data->value = 0;
	else if (ft_strcmp(name_of_fract, "julia") == 0)
	{
		data->value = 1;
		julia_init(data);
	}
	else if (ft_strcmp(name_of_fract, "burningship") == 0)
		data->value = 2;
	else
	{
		red();
		printf ("\n\tFractol chosen is not valid\n\n");
		reset();
		return (1);
	}
	return (0);
}

void	ft_init(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "Fractol project");
	data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->addr = mlx_get_data_addr(data->img,
			&data->pixel_bits, &data->line_bytes, &data->endian);
	data->x_scale = (4.0 / WINDOW_WIDTH);
	data->y_scale = (4.0 / WINDOW_WIDTH);
	data->x_center = 2.0;
	data->y_center = 2.0;
	data->maxiterations = 50;
}

void	reset_fract(t_data *data)
{
	data->x_scale = (4.0 / WINDOW_WIDTH);
	data->y_scale = (4.0 / WINDOW_WIDTH);
	data->x_center = 2.0;
	data->y_center = 2.0;
	data->maxiterations = 50;
	init_coloration(data);
	if (data->value == 0)
		mandelbrot(data);
	else if (data->value == 1)
		julia(data);
	else if (data->value == 2)
		burningship(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		data = (t_data *) malloc(sizeof(t_data));
		if (!data)
			return (-1);
		ft_init(data);
		if (fract_comp(av[1], data) == 1)
			return (0);
		mlx_key_hook(data->mlx_win, &key_press, data);
		mlx_hook(data->mlx_win, 53, 0, &closed, data);
		mlx_hook(data->mlx_win, 4, 0, &mouse_press, data);
		mlx_hook(data->mlx_win, 6, 0, &mouse_move, data);
		mlx_loop_hook(data->mlx, &hundle_no_event, data);
		mlx_loop(data->mlx);
	}
	purple();
	printf ("\n\tPlese enter a type of fractol you want\n\n");
	reset();
}
