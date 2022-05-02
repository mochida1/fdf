/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:28:23 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/02 08:15:36 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_only_x(t_gnl_list *temp, int i)
{
	if (temp->line[i] == 'x')
	{
		if (i < 2)
			return (1);
		if (temp->line[i - 1] != '0')
			return (1);
	}
	return (0);
}

static int	ch_flag(t_gnl_list *temp, int i)
{
	int	flag;

	flag = 0;
	while (i > -1)
	{
		if (convert_af(temp->line[i]))
			flag++;
		flag += check_only_x(temp, i);
		while (flag)
		{
			if (i < 1)
				return (flag);
			i--;
			if (ft_isspace_nonl(temp->line[i]))
				return (flag);
			if ((temp->line[i] == 'x') & (temp->line[i -1] == '0'))
				flag = 0;
		}
		i--;
	}
	return (flag);
}

void	check_for_letters(t_map_data *map_data, t_gnl_list *head)
{
	t_gnl_list	*temp;
	int			i;
	int			flag;

	flag = 0;
	temp = head;
	while (temp)
	{
		i = ft_strlen(temp->line);
		flag = ch_flag(temp, i);
		if (flag)
			check_for_letters_err(map_data, head);
		temp = temp->next;
	}
}
