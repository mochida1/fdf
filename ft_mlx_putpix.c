/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_putpix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 18:24:18 by hmochida          #+#    #+#             */
/*   Updated: 2021/09/29 00:50:26 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	protec_draw_pos(t_ln_in *ln_in);

/*
**yeah, all that just to draw an effing pixel on an image.
*/
void	ft_mlx_putpix(t_ln_in *ln_in, int color)
{
	char	*dst;

	if (!(protec_draw_pos(ln_in)))
		return ;
	dst = ln_in->img.addr + (ln_in->y1 * ln_in->img.line_length + ln_in->x1
			* (ln_in->img.bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

/*
**prevents ft_mlx_putpix from drawing pixels offscreen. Thus preventing wrong
**pixles overwrites and/or segfaults.
*/
static int	protec_draw_pos(t_ln_in *ln_in)
{
	if (ln_in->y1 > ln_in->img.hei || ln_in->x1 > ln_in->img.line_length
		/ (ln_in->img.bits_per_pixel / 8))
		return (0);
	if (ln_in->y1 < 0 || ln_in->x1 < 0)
		return (0);
	return (1);
}
