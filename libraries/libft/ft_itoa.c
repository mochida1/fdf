/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 21:12:29 by hmochida          #+#    #+#             */
/*   Updated: 2021/08/12 18:03:54 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getintlen(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i[2];

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i[0] = getintlen(n);
	i[1] = 0;
	if (n < 0)
	{
		n *= -1;
		i[1] = 1;
	}
	s = malloc(i[0] + 1 * (sizeof(char)));
	if (!s)
		return (0);
	s[i[0]--] = '\0';
	while (n >= 10)
	{
		s[i[0]--] = '0' + (n % 10);
		n /= 10;
	}
	s[i[0]] = '0' + (n % 10);
	if (i[1])
		s[0] = '-';
	return (s);
}
