/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 05:23:26 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/02 05:00:15 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Does what is says :| ;
*/
static void	free_some_shitty_pointers(t_gnl_list *delme)
{
	free (delme->line);
	delme->line = NULL;
	free (delme);
	delme = NULL;
}

/*
**removes all nodes comprised of a single \n from the GNL struct;
*/
t_gnl_list	*lstclean_gnl_newlines(t_gnl_list *head)
{
	t_gnl_list	*temp;
	t_gnl_list	*delme;

	while (head->line && (head->line[0] == '\n' || !(head->line[0])))
	{
		delme = head;
		head = head->next;
		free_some_shitty_pointers(delme);
	}
	temp = head;
	while (temp)
	{
		if (temp->next && (temp->next->line[0] == '\n' \
		|| !(temp->next->line[0])))
		{
			delme = temp->next;
			temp->next = temp->next->next;
			free_some_shitty_pointers(delme);
		}
		else
			temp = temp->next;
	}
	return (head);
}
