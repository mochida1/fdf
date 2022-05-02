/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 23:50:46 by hmochida          #+#    #+#             */
/*   Updated: 2021/02/19 16:39:42 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*d1;
	char	*s1;
	size_t	i;

	d1 = (char *)dst;
	s1 = (char *)src;
	i = 0;
	if (src == 0)
		return (0);
	while (i < n)
	{
		d1[i] = s1[i];
		if (s1[i] == c)
			return ((void *)(d1 + i + 1));
		i++;
	}
	return (0);
}
