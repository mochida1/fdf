/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:29:39 by hmochida          #+#    #+#             */
/*   Updated: 2022/01/03 19:30:47 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_empty_map(t_map_data *map_data, t_gnl_list *head)
{
	t_gnl_list	*temp;

	temp = head;
	while (temp)
	{
		if (temp->line[0] == '\n')
				temp = temp->next;
		else
			break ;
	}
	if (!temp)
	{
		free(map_data);
		ft_gnl_lstclear(head);
		errno = EMEDIUMTYPE;
		perror("\033[31;1mOops, failed to read map\033[0m");
		exit (0);
	}
}

/*
** Checks if lines always have the same numbers of elements;
*/
void	check_lines_len(t_map_data *map_data, t_gnl_list *head)
{
	t_gnl_list	*temp;
	int			count;

	count = 0;
	temp = head;
	while (temp)
	{
		count = ermap_get_count (map_data, temp, head);
		errmap_check_count(count, map_data, head);
		count = 0;
		temp = temp->next;
	}
}

static void	a_wild_comma_has_appeared(t_map_data *map_data, t_gnl_list *head)
{
	ft_gnl_lstclear(head);
	free(map_data);
	ft_putstr_fd("\033[31;1mError: A wild comma has appeared!\033[0m\n", 2);
	exit (0);
}

void	check_for_wild_comma(t_map_data *map_data, t_gnl_list *head)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (head->line[i] && head->line[i] != '\n')
	{
		if (head->line[i] == ',')
		{
			i++;
			if (head->line[i] != '0')
				err++;
			else
				i++;
			if (head->line[i] != 'x')
				err++;
			else
				i++;
			while (head->line[i] && ft_isdigit(head->line[i]))
				i++;
		}
		i++;
	}
	if (err)
		a_wild_comma_has_appeared(map_data, head);
}

/*
** checks if there's a hex number that is not appended to a ',';
*/
void	check_solo_hex(t_map_data *map_data, t_gnl_list *head)
{
	t_gnl_list	*temp;
	int			i;

	temp = head;
	i = 0;
	while (temp)
	{
		while (temp->line[i] && temp->line[i] != '\n')
		{
			if (temp->line[i] == '0' && temp->line[i + 1] == 'x')
			{
				if (i <= 1)
					check_solo_hex_err(map_data, head);
				else if (temp->line[i - 1] != ',')
					check_solo_hex_err(map_data, head);
				else if (!(ft_isdigit(temp->line[i - 2])))
					check_solo_hex_err(map_data, head);
			}
			i++;
		}
		i = 0;
		temp = temp->next;
	}
}
