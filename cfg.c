/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 04:56:27 by hmochida          #+#    #+#             */
/*   Updated: 2022/01/03 19:26:10 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cfg_get_default_color(t_map_data *map_data)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open("config", O_RDONLY);
	while (i++ < 5)
	{
		str = get_next_line(fd);
		free(str);
	}
	str = get_next_line(fd);
	map_data->def_max_color = ft_atoihex(&str[23]);
	free(str);
	str = get_next_line(fd);
	map_data->def_min_color = ft_atoihex(&str[23]);
	free(str);
	while (i)
	{
		str = get_next_line (fd);
		if (str == NULL)
			break ;
		free(str);
	}
	close(fd);
}

void	cfg_get_wid_hei(t_data *img)
{
	char	*temp;
	int		fd;

	fd = open("./config", O_RDONLY);
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		if (temp[0] == '3')
			img->wid = ft_atoi(&temp[17]);
		if (temp[0] == '4')
			img->hei = ft_atoi(&temp[17]);
		free (temp);
		temp = NULL;
	}
	close(fd);
}
