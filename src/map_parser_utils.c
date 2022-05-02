/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:59:19 by hmochida          #+#    #+#             */
/*   Updated: 2022/01/03 19:15:07 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	alloc_yxhc(t_map_data *map_data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	map_data->yxhc = (int ***)malloc (sizeof(int ***) * map_data->lines);
	while (y < map_data->lines)
	{
		map_data->yxhc[y] = (int **)malloc (sizeof(int **) * map_data->rows);
		while (x < map_data->rows)
		{
			map_data->yxhc[y][x] = (int *)malloc (sizeof(int) * 2);
			x++;
		}
		y++;
		x = 0;
	}
}

void	init_yxhc(t_map_data *map_data, t_gnl_list *head)
{
	ft_putstr_fd("Allocating memory to map data.\n", 1);
	alloc_yxhc (map_data);
	iterate_atoi(map_data, head);
}

/*
** Assigns values to yxhc[y][x][0];
** If a color is read, sets it on yxhc[y][x][1], else sets it as -1;
** Also gets min and max height values;
*/
void	iterate_atoi(t_map_data *map_data, t_gnl_list *head)
{
	int			y;
	t_gnl_list	*temp;

	temp = head;
	y = 0;
	while (y < map_data->lines)
	{
		iterate_atoi_x (map_data, temp, y);
		y++;
		temp = temp->next;
	}
}

void	iterate_atoi_x(t_map_data *map_data, t_gnl_list *head, int y)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (head->line[i] && x < map_data->rows)
	{
		if (check_if_height(&head->line[i]))
		{
			map_data->yxhc[y][x][0] = atoi_er(&head->line[i]);
			set_minmax_height (map_data, map_data->yxhc[y][x][0]);
			map_data->yxhc[y][x][1] = get_map_color(&head->line[i]);
			while (advance_atoiiter_counter(head->line[i]))
				i++;
			x++;
		}
		if (head->line[i] == '\0')
			break ;
		i++;
	}
}
