/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <Student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 09:02:30 by agloin            #+#    #+#             */
/*   Updated: 2020/06/15 19:09:49 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_fdf *data)
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
	if (key == 5)
		data->color_space += 1;
	if (data->color_space > 2)
		data->color_space = 0;
	if (key == 35)
		data->perspective = false;
	if (key == 34)
		data->perspective = true;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int		vallidation_first(t_fdf data)
{
	int		q;
	int		i;

	q = 1;
	i = 0;
	if (data.height < 2 || data.color_space > 1 || data.width < 2)
	{
		ft_putstr("error, it's not a rectangle\n");
		q = 0;
	}
	return (q);
}

int		vallidation_sec(char *argv)
{
	int		i;
	char	*line;
	int		fd;
	int		q;

	i = 0;
	q = 1;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		while (line[i])
		{
			if ((line[i] == 'x' && ft_isspace(line[i + 1])) || (line[i] != 32
			&& line[i] != '-' && line[i] != 'x' && (line[i] < 47
			|| line[i] > 58) && line[i] != ',' && ft_isupper(line[i]) == 0))
			{
				q = 0;
				break ;
			}
			i++;
		}
		i = 0;
		ft_strdel(&line);
	}
	return (q);
}

int		main(int argc, char **argv)
{
	t_fdf data;
	
	if (argc == 2)
	{
		read_file(argv[1], &data);
		data.mlx_ptr = mlx_init();
		data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 1000, "FDF");
		data.zoom = 20;
		data.shift_y = 200;
		data.shift_x = 200;
		draw(&data);
		mlx_key_hook(data.win_ptr, deal_key, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		ft_putstr("Usage: ./fdf [File]\n");
	return (0);
}
