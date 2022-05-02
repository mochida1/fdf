/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 11:00:59 by hmochida          #+#    #+#             */
/*   Updated: 2022/01/03 18:43:01 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*fresh;

	fresh = malloc(sizeof(t_list));
	if (!(fresh))
		return (0);
	if (content == NULL)
		(*fresh).content = NULL;
	fresh->content = content;
	(*fresh).next = NULL;
	return (fresh);
}
