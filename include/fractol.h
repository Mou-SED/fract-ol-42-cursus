/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:19:06 by moseddik          #+#    #+#             */
/*   Updated: 2022/01/21 18:49:15 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		x;
	int		y;
	int		iteration;
	int		maxiterations;
	int		bright;
	int		bright2;
	int		pixel;
	int		value;
	int		value2;
	double	c_re;
	double	c_im;
	double	a;
	double	b;
	double	aa;
	double	bb;
	double	x_scale;
	double	y_scale;
	double	x_center;
	double	y_center;
	double	julia_var_re;
	double	julia_var_im;
	double	frequenc;
}		t_data;

int		key_press(int keycode, t_data *vars);
int		mouse_press(int button, int x, int y, t_data *vars);
int		mouse_move(int x, int y, t_data *vars);
int		hundle_no_event(t_data *vars);
int		closed(t_data *vars);
int		ft_strcmp(const char *s1, const char *s2);
int		fract_comp(char *name_of_fract, t_data *data);
void	ft_init(t_data *data);
void	calcul_iter_mandelbrot(t_data *data);
void	mandelbrot(t_data *data);
void	julia(t_data *data);
void	calcul_iter_julia(t_data *data);
void	julia_init(t_data *data);
void	reset_fract(t_data *data);
void	coloration(t_data *data);
void	burningship(t_data *data);
void	calcul_iter_burningship(t_data *data);
void	blue(void);
void	red(void);
void	yellow(void);
void	purple(void);
void	reset(void);
void	init_coloration(t_data *data);

#endif