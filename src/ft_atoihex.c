/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoihex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:20:35 by hmochida          #+#    #+#             */
/*   Updated: 2022/01/03 18:53:20 by hmochida         ###   ########.fr       */
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

int	convert_af(char str)
{
	if (str == 'a' || str == 'A')
		return (10);
	if (str == 'b' || str == 'B')
		return (11);
	if (str == 'c' || str == 'C')
		return (12);
	if (str == 'd' || str == 'D')
		return (13);
	if (str == 'e' || str == 'E')
		return (14);
	if (str == 'f' || str == 'F')
		return (15);
	return (0);
}

static void	check_overflow(long ret)
{
	if (ret > INT_MAX || ret < INT_MIN)
	{
		ft_putstr_fd("\033[33;1mWARNING: Color value in map is overflown.\n", \
		2);
		ft_putstr_fd("--weird stuff might happen--\033[0m\n", 2);
	}
}

int	ft_atoihex(const char *str)
{
	long	ret;

	ret = 0;
	while (ft_isspace(*str))
		str++;
	while (*str == '0')
		str++;
	if (ft_isdigit(*str))
		ret += *str++ - 48;
	else if (convert_af(*str))
		ret += convert_af(*str++);
	while (ft_isdigit(*str) || convert_af(*str))
	{
		ret *= 16;
		if (ft_isdigit(*str))
			ret += *str++ - 48;
		else if (convert_af(*str))
			ret += convert_af(*str++);
	}
	check_overflow(ret);
	return ((int)ret);
}
