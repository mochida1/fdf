/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:31:04 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/02 05:21:27 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate45(t_map_data *map_data)
{
	int		i;
	int		j;
	float	temp_x;
	float	temp_y;

	i = 0;
	j = 0;
	while (i < map_data->lines)
	{
		while (j < map_data->rows)
		{
			temp_x = (map_data->points[i][j].x * COS45)
				+ (-1 * SIN45 * map_data->points[i][j].y);
			temp_y = (map_data->points[i][j].x * SIN45)
				+ (COS45 * map_data->points[i][j].y);
			map_data->points[i][j].x = temp_x;
			map_data->points[i][j].y = temp_y;
			j++;
		}
		j = 0;
		i++;
	}
}

void	scale_y_to_half(t_map_data *map_data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map_data->lines)
	{
		while (j < map_data->rows)
		{
			map_data->points[i][j].y = map_data->points[i][j].y * 0.5;
			j++;
		}
		j = 0;
		i++;
	}
}

float	get_orig_x_len(t_map_data *map_data)
{
	float	min_x;
	float	max_x;
	int		i[2];

	min_x = map_data->points[0][0].x;
	max_x = map_data->points[0][0].x;
	i[0] = 0;
	i[1] = 0;
	while (i[0] < map_data->lines)
	{
		while (i[1] < map_data->rows)
		{
			if (max_x < map_data->points[i[0]][i[1]].x)
				max_x = map_data->points[i[0]][i[1]].x;
			if (min_x > map_data->points[i[0]][i[1]].x)
				min_x = map_data->points[i[0]][i[1]].x;
			i[1]++;
		}
		i[0]++;
	}
	return (max_x - min_x);
}

void	scale_to_fit_x(t_data *img)
{
	float	orig_x_len;
	float	factor;

	orig_x_len = get_orig_x_len(img->map_data);
	factor = (img->wid * 0.3) / orig_x_len;
	equi_scale(img->map_data, factor);
}

void	matrix_ops(t_data *img)
{
	rotate45(img->map_data);
	scale_y_to_half(img->map_data);
	scale_to_fit_x(img);
	translate_to_center(img->map_data, img->wid, img->hei);
}
