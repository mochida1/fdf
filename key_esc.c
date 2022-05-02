/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_esc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:48:24 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/02 04:51:45 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_esc(t_data *img)
{
	ft_putstr_fd("\033[31;1mClosing FdF...\033[0m\n", 1);
	free_yxhc(img->map_data);
	free_all_points(img);
	free(img->map_data);
	mlx_destroy_image(img->mlx_ptr, img->img);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	mlx_destroy_display(img->mlx_ptr);
	free(img->mlx_ptr);
	free(img);
	ft_putstr_fd("\033[32;1mFdF closed successfully.\033[0m\n", 1);
	exit (0);
}

int	red_x_close(t_data *img)
{
	ft_putstr_fd("\033[31;1mClosing FdF...\033[0m\n", 1);
	free_yxhc(img->map_data);
	free_all_points(img);
	free(img->map_data);
	mlx_destroy_image(img->mlx_ptr, img->img);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	mlx_destroy_display(img->mlx_ptr);
	free(img->mlx_ptr);
	free(img);
	ft_putstr_fd("\033[32;1mFdF closed successfully.\033[0m\n", 1);
	exit (0);
	return (0);
}
