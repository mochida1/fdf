/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 05:54:35 by hmochida          #+#    #+#             */
/*   Updated: 2021/10/05 00:05:17 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		color_step_mixer(t_color color, t_ln_in ln_in, t_brese brese);
static t_color	color_init(t_ln_in ln_in, t_brese brese);

/*
**gets difference from received colors and gives the color for each step of
**bresenham's algo.
*/
int	get_color(t_ln_in ln_in, t_brese brese)
{
	t_color	color;

	color = color_init(ln_in, brese);
	color.ret = color_step_mixer(color, ln_in, brese);
	return (color.ret);
}

/*
**Mixes split colors back into a single value and adds the relative delta so
**that the returned color can make a smooth gradient when put
**alongside other pixels;
*/
static int	color_step_mixer(t_color color, t_ln_in ln_in, t_brese brese)
{
	int		r;
	int		g;
	int		b;
	float	progress;

	progress = ((float) brese.i / (float) color.steps);
	r = color.r_delta * progress;
	if (r < -255)
		r = 0;
	else if (r > 255)
		r = 255;
	r = r << 16;
	g = color.g_delta * progress;
	if (g < -255)
		g = 0;
	else if (g > 255)
		g = 255;
	g = g << 8;
	b = color.b_delta * progress;
	if (b < -255)
		b = 0;
	else if (b > 255)
		b = 255;
	return (ln_in.color1 + r + g + b);
}

/* 
**splits received colors from ln_in into 8 bit channels;
*/
static t_color	color_init(t_ln_in ln_in, t_brese brese)
{
	t_color	color;

	if (brese.adx > brese.ady)
		color.steps = brese.adx;
	else
		color.steps = brese.ady;
	color.c1r = RED_MAX & ln_in.color1;
	color.c1r = color.c1r >> 16;
	color.c1g = GREEN_MAX & ln_in.color1;
	color.c1g = color.c1g >> 8;
	color.c1b = BLUE_MAX & ln_in.color1;
	color.c2r = RED_MAX & ln_in.color2;
	color.c2r = color.c2r >> 16;
	color.c2g = GREEN_MAX & ln_in.color2;
	color.c2g = color.c2g >> 8;
	color.c2b = BLUE_MAX & ln_in.color2;
	color.r_delta = (color.c2r - color.c1r);
	color.g_delta = (color.c2g - color.c1g);
	color.b_delta = (color.c2b - color.c1b);
	return (color);
}
