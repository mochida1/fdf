/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_er.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:49:26 by hmochida          #+#    #+#             */
/*   Updated: 2022/01/03 19:27:34 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_isspace(const char c)
{
	if (c == 32 || (c > 8 && c < 14))
		return ((int)c);
	else
		return (0);
}

static void	check_overflow(long ret)
{
	if (ret > INT_MAX || ret < INT_MIN)
	{
		ft_putstr_fd("\033[33;1mWARNING: \
		Int over/underflow detected on map.\n", 2);
		ft_putstr_fd("       --weird stuff might happen--\033[0m\n", 2);
	}
}

void	free_some_pointers(t_map_data *map_data, t_gnl_list *head)
{
	free_yxhc(map_data);
	ft_gnl_lstclear(head);
	free(map_data);
}

int	atoi_er(const char *str)
{
	long	ret;
	int		m;

	ret = 0;
	m = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		m = -1;
		str++;
	}
	while (*str == '0')
		str++;
	if (ft_isdigit(*str))
		ret += *str++ - 48;
	while (ft_isdigit(*str))
	{
		ret *= 10;
		ret += *str++ - 48;
	}
	check_overflow(ret);
	return ((int)ret * m);
}
