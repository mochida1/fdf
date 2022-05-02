/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_event_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:49:09 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/02 05:40:30 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	event_handler(t_data *img)
{
	mlx_hook(img->win_ptr, X_KEYPRESS, 1L << 0, key_press, img);
	mlx_hook(img->win_ptr, RED_X, 1L << 17, red_x_close, img);
	mlx_expose_hook(img->win_ptr, &render, img);
}

int	key_press(int keycode, t_data *img)
{
	int	i;

	i = 0;
	i = keymap00(keycode, img);
	if (i)
		i = keymap01(keycode, img);
	if (i)
		i = keymap02(keycode, img);
	return (0);
}
