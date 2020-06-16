/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <Student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 13:07:36 by agloin            #+#    #+#             */
/*   Updated: 2020/06/15 19:05:36 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	isometric(float *x, float *y, int *z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - *z;
}

void	bresenham3(t_fdf *data)
{
	data->z = data->z_matrix[(int)data->y][(int)data->x];
	data->z1 = data->z_matrix[(int)data->y1][(int)data->x1];
	data->x = data->x * data->zoom;
	data->y = data->y * data->zoom;
	data->x1 = data->x1 * data->zoom;
	data->y1 = data->y1 * data->zoom;
	data->color = (data->z || data->z1) ? 0xe80c0c : 0xffffff;
	data->x_step = data->x1 - data->x;
	data->y_step = data->y1 - data->y;
	if (data->perspective == false)
	{
		isometric(&data->x, &data->y, &data->z);
		isometric(&data->x1, &data->y1, &data->z1);
	}
}

void	bresenham2(t_fdf *data)
{
	bresenham3(data);
	data->x = data->x + data->shift_x;
	data->y = data->y + data->shift_y;
	data->x1 = data->x1 + data->shift_x;
	data->y1 = data->y1 + data->shift_y;
	data->x_step = data->x1 - data->x;
	data->y_step = data->y1 - data->y;
	data->max = ft_max1(ft_mod(data->x_step), ft_mod(data->y_step));
	data->x_step = data->x_step / data->max;
	data->y_step = data->y_step / data->max;
	while ((int)(data->x - data->x1) || (int)(data->y - data->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y, data->color);
		data->x = data->x + data->x_step;
		data->y = data->y + data->y_step;
	}
}

void	draw2(t_fdf *data, float x, float y)
{
	if (x < data->width - 1)
	{
		data->x = x;
			data->y = y;
			data->x1 = x + 1;
				data->y1 = y;
				bresenham2(data);
			}
			if (y < data->height - 1)
			{
				data->x = x;
				data->y = y;
				data->x1 = data->x;
				data->y1 = data->y + 1;
				bresenham2(data);
			}
}

void	draw(t_fdf *data)
{
	float x;
	float y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			draw2(data, x, y);
			x++;
		}
		y++;
	}
}
