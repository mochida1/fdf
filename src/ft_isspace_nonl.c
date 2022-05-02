/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace_nonl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 07:03:52 by hmochida          #+#    #+#             */
/*   Updated: 2022/01/03 19:36:16 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** checks if character is invisibru;
*/
int	ft_isspace_nonl(char c)
{
	if (c == 32 || (c > 8 && c < 14 && c != 10))
		return (c);
	return (0);
}
