/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_seq_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:02:58 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/02 04:55:38 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** frees all points until row_index/lines_index. 
*/
void	free_points(t_data *img, int row_index)
{
	while (row_index >= 0)
	{
		free(img->map_data->points[row_index]);
		row_index--;
	}
	free(img->map_data->points);
}

void	free_all_points(t_data *img)
{
	int	i;

	i = img->map_data->lines - 1;
	while (i >= 0)
	{
		free(img->map_data->points[i]);
		i--;
	}
	free(img->map_data->points);
}
