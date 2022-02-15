/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:19:46 by moseddik          #+#    #+#             */
/*   Updated: 2022/01/21 19:06:13 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	closed(t_data *vars)
{
	(void)vars;
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	free(vars);
	exit(0);
}

int	hundle_no_event(t_data *vars)
{
	if (vars->value == 0)
		mandelbrot(vars);
	else if (vars->value == 1)
		julia(vars);
	else if (vars->value == 2)
		burningship(vars);
	return (0);
}

int	key_press(int keycode, t_data *vars)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 126)
		vars->y_center += 30 * vars->x_scale;
	else if (keycode == 125)
		vars->y_center -= 30 * vars->x_scale;
	else if (keycode == 124)
		vars->x_center -= 30 * vars->x_scale;
	else if (keycode == 123)
		vars->x_center += 30 * vars->x_scale;
	else if (keycode == 69)
		vars->maxiterations += 50;
	else if (keycode == 78)
		vars->maxiterations -= 50;
	else if (keycode == 15)
		reset_fract(vars);
	else if (keycode == 83
		&& (vars->frequenc >= 0 && vars->frequenc <= 15))
		vars->frequenc = (vars->frequenc + 1.2) * 1;
	return (0);
}

int	mouse_press(int button, int x, int y, t_data *vars)
{
	if (button == 4)
	{
		vars->x_scale *= 0.5;
		vars->y_scale *= 0.5;
		vars->maxiterations += 20;
		vars->x_center = vars->x_center - (x * vars->x_scale);
		vars->y_center = vars->y_center - (y * vars->y_scale);
	}
	else if (button == 5)
	{
		vars->x_center = vars->x_center + (x * vars->x_scale);
		vars->y_center = vars->y_center + (y * vars->y_scale);
		vars->x_scale /= 0.5;
		vars->y_scale /= 0.5;
		vars->maxiterations -= 20;
	}
	else if (button == 1)
		vars->value2 += 1;
	return (0);
}

int	mouse_move(int x, int y, t_data *vars)
{
	if (vars->value2 % 2)
	{
		if (x >= 0 && x <= WINDOW_WIDTH && y >= 0 && y <= WINDOW_WIDTH)
		{
			vars->julia_var_re = (vars->x_scale * x) - vars->x_center;
			vars->julia_var_im = (vars->x_scale * y) - vars->y_center;
		}
		else
			return (0);
	}
	else if (!vars->value2 % 2)
	{
		vars->julia_var_re = vars->julia_var_re;
		vars->julia_var_im = vars->julia_var_im;
	}
	return (0);
}
