/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:02:17 by moseddik          #+#    #+#             */
/*   Updated: 2022/01/21 17:58:54 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	red(void)
{
	printf("\033[1;31m");
}

void	blue(void)
{
	printf("\033[0;34m");
}

void	yellow(void)
{
	printf("\033[0;33m");
}

void	purple(void)
{
	printf("\033[0;35m");
}

void	reset(void)
{
	printf("\033[0m");
}
