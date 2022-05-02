/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:41:24 by hmochida          #+#    #+#             */
/*   Updated: 2022/01/03 18:44:32 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (!n || dst == src)
		return (dst);
	i = 0;
	d = dst;
	s = (unsigned char *)src;
	while (i < n)
	{
		*d = *s;
		i++;
		d++;
		s++;
	}
	return (dst);
}
