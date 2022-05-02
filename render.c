/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 08:53:18 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/02 05:20:01 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_all_shit(t_data *img)
{
	int		i[2];
	t_ln_in	line;

	i[0] = 0;
	i[1] = 0;
	line.img = *img;
	while (i[0] < img->map_data->lines)
	{
		while (i[1] < img->map_data->rows)
		{
			if (i[1] + 1 != img->map_data->rows)
			{
				update_line(&line, img->map_data->points[i[0]][i[1]],
					img->map_data->points[i[0]][i[1] + 1]);
			}
			if (i[0] + 1 != img->map_data->lines)
			{
				update_line(&line, img->map_data->points[i[0]][i[1]],
					img->map_data->points[i[0] + 1][i[1]]);
			}
			i[1]++;
		}
		i[1] = 0;
		i[0]++;
	}
}

void	update_line(t_ln_in *line, t_points pt1, t_points pt2)
{
	line->x1 = pt1.x;
	line->x2 = pt2.x;
	line->y1 = pt1.y - (pt1.z * X_WEIGHT / 2);
	line->y2 = pt2.y - (pt2.z * X_WEIGHT / 2);
	line->color1 = pt1.color;
	line->color2 = pt2.color;
	ft_mlx_putln(*line);
}

int	render(t_data *img)
{
	draw_all_shit(img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
	return (0);
}
