/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 09:02:30 by agloin            #+#    #+#             */
/*   Updated: 2020/03/15 09:02:36 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, fdf *data)
{
	if (key == 126)
		data->shift_y = data->shift_y - 10;
	if (key == 125)
		data->shift_y = data->shift_y + 10;
	if (key == 123)
		data->shift_x = data->shift_x - 10;
	if (key == 124)
		data->shift_x = data->shift_x + 10;
	if (key == 53)
		exit(0);
	if (key == 35)
		data->perspective = false;
	if (key == 34)
		data->perspective = true;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return(0);
}

void	freee(fdf *data)
{
	int i;

	i = 0;
	if (data->z_matrix)
	{
		while (i < data->height)
			free(data->z_matrix[i++]);
		free(data->z_matrix);
	}
}

int		main(int argc, char **argv)
{
	fdf *data;

	if (argc == 2)
	{
		data = (fdf *)malloc(sizeof(fdf));
        read_file(argv[1], data);
        data->mlx_ptr = mlx_init();
        data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
        data->zoom = 20;
        data->shift_y = 200;
        data->shift_x = 200;
        draw(data);
        mlx_key_hook(data->win_ptr, deal_key, data);
        mlx_loop(data->mlx_ptr);
	}
	return(0);
}