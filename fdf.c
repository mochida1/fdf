/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 05:25:33 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/02 04:56:05 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_data	*img;

	check_args(argc, argv);
	img = malloc (sizeof(t_data));
	init_mlx_data (img, argv);
	matrix_ops(img);
	render(img);
	event_handler(img);
	mlx_loop(img->mlx_ptr);
	return (0);
}
