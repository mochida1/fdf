/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:00:39 by hmochida          #+#    #+#             */
/*   Updated: 2022/01/03 19:18:24 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** creates a new node containing a line of a file;
*/
t_gnl_list	*ft_gnl_lstnew(int fd)
{
	t_gnl_list	*fresh;

	fresh = malloc(sizeof(t_gnl_list));
	if (!(fresh))
		return (0);
	if (fd == 0)
		fresh->line = NULL;
	fresh->line = get_next_line(fd);
	if (!(fresh->line))
	{
		free (fresh);
		return (0);
	}
	fresh->next = NULL;
	return (fresh);
}

/*
** iterates to the last node of the GNL list
*/
t_gnl_list	*ft_gnl_lstlast(t_gnl_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/*
** adds a GNL node to the end on the list
*/
void	ft_gnl_lstadd_back(t_gnl_list **lst, t_gnl_list *new)
{
	t_gnl_list	*temp;

	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_gnl_lstlast(*lst);
	temp->next = new;
}

/*
** adds a GNL node to the end on the list
*/
int	ft_gnl_lstpopulate(int fd, t_gnl_list **start)
{
	t_gnl_list	*new;

	new = ft_gnl_lstnew(fd);
	if (!(new))
		return (0);
	ft_gnl_lstadd_back(start, new);
	return (1);
}

/*
** clears the WHOLE list;
*/
void	ft_gnl_lstclear(t_gnl_list *lst)
{
	t_gnl_list	*temp;

	temp = lst;
	if (temp == NULL)
		return ;
	while (temp != NULL)
	{
		temp->next = lst->next;
		temp = temp->next;
		free(lst->line);
		free(lst);
		lst = temp;
	}
	lst = NULL;
}
