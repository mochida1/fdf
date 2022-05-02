/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_keymap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:53:33 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/02 05:16:21 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** actions for keycodes ESC, Q, W, E
*/
int	keymap00(int keycode, t_data *img)
{
	if (keycode == KEY_ESC)
		key_esc(img);
	else if (keycode == KEY_Q)
	{
		return (0);
	}
	else if (keycode == KEY_E)
	{
		return (0);
	}
	else if (keycode == KEY_W)
	{
		return (0);
	}
	return (1);
}

/*
** placeholder. actions for keycodes A, S , D
*/
int	keymap01(int keycode, t_data *img)
{
	if (keycode == KEY_A)
	{
		return (img->wid);
	}
	else if (keycode == KEY_S)
	{
		return (0);
	}
	else if (keycode == KEY_D)
	{
		return (0);
	}
	return (1);
}

/*
** placeholder. actions for keycodes R, F, Z, C
*/
int	keymap02(int keycode, t_data *img)
{
	if (keycode == KEY_R)
	{
		return (img->wid);
	}
	else if (keycode == KEY_F)
	{
		return (0);
	}
	else if (keycode == KEY_Z)
	{
		return (0);
	}
	else if (keycode == KEY_C)
	{
		return (0);
	}
	return (1);
}

/*
** placeholder. actions for keycodes I, O, P, SPACE.
*/
int	keymap03(int keycode, t_data *img)
{
	if (keycode == KEY_I)
	{
		return (img->wid);
	}
	else if (keycode == KEY_O)
	{
		return (0);
	}
	else if (keycode == KEY_P)
	{
		return (0);
	}
	else if (keycode == KEY_SPACE)
	{
		return (0);
	}
	return (1);
}
