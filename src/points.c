/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:52:35 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/02 04:59:07 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_points(t_data *img)
{
	int	iy;
	int	ix;

	iy = 0;
	ix = 0;
	img->map_data->points = malloc (sizeof(t_points *) * img->map_data->lines);
	if (!img->map_data->points)
		exit_prerender(img);
	while (iy < img->map_data->lines)
	{
		img->map_data->points[iy] = malloc (sizeof(t_points)
				* img->map_data->rows);
		if (!img->map_data->points[iy])
			exit_prerender01(img, iy);
		while (ix < img->map_data->rows)
		{
			img->map_data->points[iy][ix].x = 0;
			img->map_data->points[iy][ix].y = 0;
			img->map_data->points[iy][ix].z = 0;
			img->map_data->points[iy][ix].color = 0;
			ix++;
		}
		ix = 0;
		iy++;
	}
}

void	get_points(t_data *img)
{
	int	iy;
	int	ix;

	iy = 0;
	ix = 0;
	while (iy < img->map_data->lines)
	{
		while (ix < img->map_data->rows)
		{
			copy_points(img, ix, iy);
			ix++;
		}
		ix = 0;
		iy++;
	}
}

/*
** copy points and center coordinates at world 0,0,0;
*/
void	copy_points(t_data *img, int ix, int iy)
{
	float	ky;
	float	kx;

	ky = img->map_data->lines / 2;
	kx = img->map_data->rows / 2;
	if (ky < 1)
		ky = 0;
	if (kx < 1)
		kx = 0;
	img->map_data->points[iy][ix].x = ix - kx;
	img->map_data->points[iy][ix].y = iy - ky;
	img->map_data->points[iy][ix].z = img->map_data->yxhc[iy][ix][0];
	if (img->map_data->yxhc[iy][ix][1] == -1)
	{
		img->map_data->points[iy][ix].color
			= get_def_color(img->map_data, img->map_data->yxhc[iy][ix][0]);
	}
	else
		img->map_data->points[iy][ix].color = img->map_data->yxhc[iy][ix][1];
}

void	point_wrapper(t_data *img)
{
	init_points(img);
	get_points(img);
}
