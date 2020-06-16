/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <Student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 09:03:18 by agloin            #+#    #+#             */
/*   Updated: 2020/06/15 18:57:25 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>

typedef		enum
{
	true,
	false
}			t_bool;

typedef		struct
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		color_space;
	void	*mlx_ptr;
	void	*win_ptr;
	t_bool	perspective;
	float	x;
	float	y;
	float	x1;
	float	y1;
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;
}			t_fdf;

void		read_file(char *file_name, t_fdf *data);
void		bresenham(float x, float y, float x1, float y1, t_fdf *data);
void		draw(t_fdf *data);
void		freee(t_fdf *data);

#endif
