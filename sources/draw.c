/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 13:07:36 by agloin            #+#    #+#             */
/*   Updated: 2020/03/15 13:07:38 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

float	ft_max1(float a, float b)
{
	if (a > b)
		return(a);
	return (b);
}

float	ft_mod(float a)
{
	if (a < 0)
		return(-a);
	return(a);
}

void	isometric(float *x, float *y, int *z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - *z;
}

void	bresenham(float x, float y, float x1, float y1, fdf *data)// ([1:1] [3:12] - координаты двух точек [y, x]
{
	float x_step;
	float y_step;
	int max;
	int z;
	int z1;

	// data->perspective = true;
	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];


	//-----------zoom------------
	x = x * data->zoom;
	y = y * data->zoom;
	x1 = x1 * data->zoom;
	y1 = y1 * data->zoom;
	//---------color-------------
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	x_step = x1 - x;
	y_step = y1 - y;
	//-------3D------------------
	if (data->perspective == false)
	{
		isometric(&x, &y, &z);
		isometric(&x1, &y1, &z1);
	}
	//-------------shift---------
	x = x + data->shift_x;
	y = y + data->shift_y;
	x1 = x1 + data->shift_x;
	y1 = y1 + data->shift_y;

	x_step = x1 - x;
	y_step = y1 - y;
	max = ft_max1(ft_mod(x_step), ft_mod(y_step));
	x_step = x_step / max;
	y_step = y_step / max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x = x + x_step;
		y = y + y_step;
	}

}

void	draw(fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
