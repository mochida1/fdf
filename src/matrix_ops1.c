/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 01:48:42 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/02 04:53:06 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	equi_scale(t_map_data *map_data, float factor)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map_data->lines)
	{
		while (j < map_data->rows)
		{
			map_data->points[i][j].x = map_data->points[i][j].x * factor;
			map_data->points[i][j].y = map_data->points[i][j].y * factor;
			map_data->points[i][j].z = map_data->points[i][j].z * factor;
			j++;
		}
		j = 0;
		i++;
	}
}

void	translate_to_center(t_map_data *map_data, int wid, int hei)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map_data->lines)
	{
		while (j < map_data->rows)
		{
			map_data->points[i][j].x += (float) wid / 2;
			map_data->points[i][j].y += (float) hei / 2;
			j++;
		}
		j = 0;
		i++;
	}
}
