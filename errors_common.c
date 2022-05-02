/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_common.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:34:17 by hmochida          #+#    #+#             */
/*   Updated: 2022/01/03 19:35:28 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_yxhc(t_map_data *map_data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < map_data->lines)
	{
		while (x < map_data->rows)
		{
			free (map_data->yxhc[y][x++]);
		}
		x = 0;
		free (map_data->yxhc[y++]);
	}
	free (map_data->yxhc);
}
