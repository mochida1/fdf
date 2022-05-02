/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:01:56 by hmochida          #+#    #+#             */
/*   Updated: 2022/01/03 18:45:05 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkcarr(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	s1_len;
	size_t	i;

	if (!s1)
		return (NULL);
	while (checkcarr(*s1, set))
		s1++;
	if (*s1 == '\0')
	{
		s2 = malloc(1 * (sizeof(char)));
		s2[0] = '\0';
		return (s2);
	}
	s1_len = (size_t)ft_strlen(s1);
	while (checkcarr(s1[s1_len - 1], set))
		s1_len--;
	s2 = malloc((s1_len) * (sizeof(char)));
	if (!s2)
		return (0);
	i = 0;
	while (i < s1_len)
		s2[i++] = *s1++;
	s2[i] = '\0';
	return (s2);
}
