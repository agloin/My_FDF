/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <Student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 09:18:05 by agloin            #+#    #+#             */
/*   Updated: 2020/06/15 19:17:57 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		ft_strdel(&line);
	}
	close(fd);
	return (height);
}

int		get_width(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		width;
	int		counter;

	counter = 0;
	fd = open(file_name, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		width = ft_count_words(line, ' ');
		if (width != data->color_space)
		{
			data->color_space = width;
			counter++;
		}
		ft_strdel(&line);
	}
	data->color_space = counter;
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_putstr("Could not open file\n");
		exit(0);
	}
	data->height = get_height(file_name);
	data->width = get_width(file_name, data);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i++], line);
		ft_strdel(&line);
	}
	close(fd);
}
