/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 09:03:18 by agloin            #+#    #+#             */
/*   Updated: 2020/03/15 09:03:20 by agloin           ###   ########.fr       */
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

typedef enum
{
	true,
	false
}			t_bool;

typedef struct
{
	int		width; // ширина карты
	int		height; // высота карты
	int		**z_matrix; // z-координата карты
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	void	*mlx_ptr;
	void	*win_ptr;
	t_bool  perspective;
}			fdf;

void	read_file(char *file_name, fdf *data);
void	bresenham(float x, float y, float x1, float y1, fdf *data);
void	draw(fdf *data);

#endif