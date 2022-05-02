/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:41:59 by hmochida          #+#    #+#             */
/*   Updated: 2021/09/21 22:48:23 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**gets absoulute value of int x, because screw maths.h;
*/
int	ft_iabs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}
