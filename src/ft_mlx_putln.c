/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_putln.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:26:17 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/01 18:25:48 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_brese	brese_init(t_ln_in ln_in);
static int		lil_slope(t_ln_in ln_in, t_brese brese);
static int		big_slope(t_ln_in ln_in, t_brese brese);

/*
**draws a line from x1,x1 to x2,y2 in *img.img
*/
int	ft_mlx_putln(t_ln_in ln_in)
{
	t_brese	brese;
	int		x;

	x = 0;
	if (ln_in.x1 == ln_in.x2 && ln_in.y1 == ln_in.y2)
		return (0);
	brese = brese_init(ln_in);
	if (brese.adx > brese.ady)
		x = lil_slope(ln_in, brese);
	else
		x = big_slope(ln_in, brese);
	return (x);
}

/*
**initializes struct for bresenham's and putpix
*/
static t_brese	brese_init(t_ln_in ln_in)
{
	t_brese	a;

	a.dx = ln_in.x2 - ln_in.x1;
	a.dy = ln_in.y2 - ln_in.y1;
	a.adx = ft_iabs(a.dx);
	a.ady = ft_iabs(a.dy);
	a.k = 0;
	a.i = 0;
	a.sx = 1;
	a.sy = 1;
	if (a.dx < 0)
		a.sx = -1;
	if (a.dy < 0)
		a.sy = -1;
	return (a);
}

/*
**bresenham's 1st half. Deals with slopes lower than 45º
*/
static int	lil_slope(t_ln_in ln_in, t_brese brese)
{
	ft_mlx_putpix(&ln_in, get_color(ln_in, brese));
	brese.k = (2 * brese.ady) - brese.adx;
	while (brese.i < brese.adx)
	{
		brese.i++;
		ln_in.x1 += brese.sx;
		if (brese.k < 0)
			brese.k += (2 * brese.ady);
		else
		{
			ln_in.y1 += brese.sy;
			brese.k += (2 * brese.ady) - (2 * brese.adx);
		}
		ft_mlx_putpix(&ln_in, get_color(ln_in, brese));
	}
	return (1);
}

/*
**bresenham's 2nd half. Deals with slopes higher than 45º
*/
static int	big_slope(t_ln_in ln_in, t_brese brese)
{
	ft_mlx_putpix(&ln_in, get_color(ln_in, brese));
	brese.k = (2 * brese.adx) - brese.ady;
	while (brese.i < brese.ady)
	{
		brese.i++;
		ln_in.y1 += brese.sy;
		if (brese.k < 0)
			brese.k += (2 * brese.adx);
		else
		{
			ln_in.x1 += brese.sx;
			brese.k += (2 * brese.adx) - (2 * brese.ady);
		}
		ft_mlx_putpix(&ln_in, get_color(ln_in, brese));
	}
	return (1);
}
