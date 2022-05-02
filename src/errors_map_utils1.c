/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:51:44 by hmochida          #+#    #+#             */
/*   Updated: 2022/01/03 19:24:55 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_solo_hex_err(t_map_data *map_data, t_gnl_list *head)
{
	ft_putstr_fd("Error: hex not paired to int.\n", 2);
	ft_gnl_lstclear(head);
	free(map_data);
	exit (0);
}

void	check_for_letters_err(t_map_data *map_data, t_gnl_list *head)
{
	ft_putstr_fd("Error: found a lost string.\n", 2);
	ft_gnl_lstclear(head);
	free(map_data);
	exit (0);
}
