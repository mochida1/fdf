/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_seq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:41:03 by hmochida          #+#    #+#             */
/*   Updated: 2022/01/07 21:34:37 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_prerender(t_data *img)
{
	ft_putstr_fd("\033[31;1mAborting FDF!\033[0m\n", 1);
	free_yxhc(img->map_data);
	free(img->map_data);
	mlx_destroy_image(img->mlx_ptr, img->img);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	mlx_destroy_display(img->mlx_ptr);
	free(img->mlx_ptr);
	free(img);
	ft_putstr_fd ("\033[31;1mError: Out of memmory.\033[0m\n", 1);
	exit (0);
}

void	exit_prerender01(t_data *img, int row_index)
{
	ft_putstr_fd("\033[31;1mAborting FDF!\033[0m\n", 1);
	free_yxhc(img->map_data);
	free_points(img, row_index);
	free(img->map_data);
	mlx_destroy_image(img->mlx_ptr, img->img);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	mlx_destroy_display(img->mlx_ptr);
	free(img->mlx_ptr);
	free(img);
	ft_putstr_fd ("\033[31;1mError: Out of memmory.\033[0m\n", 1);
	exit (0);
}
