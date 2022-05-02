/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_def_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:59:44 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/02 05:41:58 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_def_color(t_map_data *map_data, int height)
{
	int		delta_hrgb[4];
	float	k;
	int		ret;

	delta_hrgb[0] = map_data->max_height - map_data->min_height;
	k = ((float) height - (float) map_data->min_height) / (float) delta_hrgb[0];
	delta_hrgb[1] = ((RED_MAX & map_data->def_max_color) >> 16)
		- ((RED_MAX & map_data->def_min_color) >> 16);
	delta_hrgb[2] = ((GREEN_MAX & map_data->def_max_color) >> 8)
		- ((GREEN_MAX & map_data->def_min_color) >> 8);
	delta_hrgb[3] = (BLUE_MAX & map_data->def_max_color)
		- (BLUE_MAX & map_data->def_min_color);
	ret = delta_hrgb[1] * k;
	ret = ret << 8;
	ret += delta_hrgb[2] * k;
	ret = ret << 8;
	ret += delta_hrgb[3] * k;
	return (map_data->def_min_color + ret);
}
