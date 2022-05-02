/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:24:30 by hmochida          #+#    #+#             */
/*   Updated: 2021/02/19 18:24:58 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		ctrl;
	char	*hay;
	size_t	nlen;

	nlen = (size_t)ft_strlen(needle);
	hay = (char *)haystack;
	if (nlen == 0)
		return (hay);
	while (*hay && len-- && len + 1 >= nlen)
	{
		ctrl = 0;
		while (hay[ctrl] == needle[ctrl])
		{
			if (ctrl + 1 == (int)nlen)
				return (hay);
			ctrl++;
		}
		hay++;
	}
	return (NULL);
}
