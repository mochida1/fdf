/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:56:48 by hmochida          #+#    #+#             */
/*   Updated: 2022/01/03 19:12:52 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_if_height(const char *str)
{
	if (*str == '-' || (ft_isdigit(*str)))
	{
		return (1);
	}
	return (0);
}

int	get_map_color(const char *str)
{
	char	*temp;
	int		ret;

	ret = -1;
	temp = (char *)str;
	while (*temp != ',' && advance_atoiiter_counter(*temp))
		temp++;
	if (*temp == ',')
	{
		temp += 3;
		ret = ft_atoihex(temp);
	}
	return (ret);
}

void	set_minmax_height(t_map_data *map_data, int height)
{
	static int	x;

	if (!x)
	{
		map_data->max_height = height;
		map_data->min_height = height;
		x = 1;
	}
	if (height > map_data->max_height)
		map_data->max_height = height;
	if (height < map_data->min_height)
		map_data->min_height = height;
}

int	advance_atoiiter_counter(const char c)
{
	if (ft_isspace_nonl(c))
		return (0);
	if (c == '\n')
		return (0);
	if (c == '\0')
		return (0);
	return (1);
}
