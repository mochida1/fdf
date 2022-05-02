/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 00:25:39 by hmochida          #+#    #+#             */
/*   Updated: 2022/01/08 18:10:13 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx_data(t_data *img, char **argv)
{
	img->map_data = get_map(argv[1]);
	ft_putstr_fd("Initializing MLX.\n", 1);
	img->mlx_ptr = mlx_init();
	cfg_get_wid_hei(img);
	img->win_ptr = mlx_new_window(img->mlx_ptr, img->wid, img->hei, \
	"FDF:hmochida");
	img->img = mlx_new_image(img->mlx_ptr, img->wid, img->hei);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
	ft_putstr_fd("\033[32;1mMLX successfully initialized.\033[0m\n", 1);
	point_wrapper(img);
}
