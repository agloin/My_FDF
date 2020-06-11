/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 09:18:05 by agloin            #+#    #+#             */
/*   Updated: 2020/03/15 09:18:07 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_height(char *file_name)
{
	char *line;
	int fd;
	int height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	//free(line);
	close(fd);
	return(height);
}

int		get_width(char *file_name)
{
	char *line;;
	int fd;
	int width;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_count_words(line, ' ');
	free(line); //---------------check it---------------------------
	close(fd);
	return(width);
}

void	fill_matrix(int *z_line, char *line, int k)
{
	char **nums;
	int i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (k--)
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, fdf *data)
{
	int fd;
	char *line;
	int i;

	data->height = get_height(file_name); // получили высоту
	data->width = get_width(file_name); // получили длину
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height)); //выделяем память
	i = 0;
	while (i <= data->height)
	{
		data->z_matrix[i] = (int *) malloc(sizeof(int) * (data->width));
		i++;
	}
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line) && i < data->height)
	{
		fill_matrix(data->z_matrix[i], line, data->width);
		free(line);
		i++;
	}
	close(fd);
}
