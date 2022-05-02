/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 03:43:37 by hmochida          #+#    #+#             */
/*   Updated: 2021/02/13 00:49:14 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i)
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i--;
	}
	if (i == 0 && s[i] == (char)c)
		return ((char *)s);
	return (NULL);
}
