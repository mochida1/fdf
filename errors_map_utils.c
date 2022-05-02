/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:11:44 by hmochida          #+#    #+#             */
/*   Updated: 2022/01/03 19:00:43 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ermap_get_count(t_map_data *map_data, t_gnl_list *temp, t_gnl_list *head)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (temp->line[i] && temp->line[i] != '\n')
	{
		check_invalid_char(temp->line[i], map_data, head);
		while (ft_isspace_nonl(temp->line[i]) || (temp->line[i] == '-'))
			check_invalid_char(temp->line[i++], map_data, head);
		if (temp->line[i] == '\n' || temp->line[i] == '\0')
			break ;
		while (temp->line[i] && !(ft_isspace_nonl(temp->line[i])
				&& temp->line[i] != '\n'))
		{
			if (temp->line[i] == ',')
				errmap_check_hexfmt(&temp->line[i + 1], map_data, head);
			check_invalid_char(temp->line[i], map_data, head);
			i++;
		}
		count++;
	}
	return (count);
}

int	check_invalid_char(char c, t_map_data *map_data, t_gnl_list *head)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if ((c >= 'a' && c <= 'f') || c == 'x')
		return (1);
	else if (c >= 'A' && c <= 'F')
		return (1);
	else if ((ft_isspace_nonl(c)))
		return (1);
	else if (c == '\n' || c == ',' || c == '-')
		return (1);
	ft_putstr_fd("Error: map has invalid character.\n", 2);
	ft_gnl_lstclear(head);
	free(map_data);
	exit(0);
}

void	errmap_check_count(int count, t_map_data *map_data, t_gnl_list *head)
{
	if ((count) != map_data->rows)
	{
		errno = ENOMSG;
		perror("A map line has the wrong number of elements D");
		ft_gnl_lstclear(head);
		free(map_data);
		exit(0);
	}
	if (count > 1920)
	{
		ft_putstr_fd("Error: map with over 1920 elements IN A LINE!\n", 2);
		ft_gnl_lstclear(head);
		free(map_data);
		exit(0);
	}
}

void	errmap_check_hexfmt(char *str, t_map_data *map_data, t_gnl_list *head)
{
	int	i;

	i = 0;
	if (*str == '0' && (str[i + 1] == 'x'))
		str += 2;
	while (*str == '0')
		str++;
	while (ft_isdigit(str[i]) || convert_af(str[i]))
		i++;
	if ((ft_isspace_nonl(str[i]) || str[i] == '\n' || str[i] == 0) && i <= 8)
		return ;
	ft_putstr_fd("Error: Invalid hex format found in map\n", 2);
	ft_gnl_lstclear(head);
	free(map_data);
	exit (0);
}

void	check_if_only_one_y_or_x(t_map_data *map_data, t_gnl_list *head)
{
	int	err;

	err = 0;
	if (map_data->lines < 2)
	{
		err++;
		ft_putstr_fd("\033[31;1mERROR: Map has less than 2 lines\033[0m\n", 2);
	}
	if (map_data->rows < 2)
	{
		err++;
		ft_putstr_fd("\033[31;1mERROR: Map has less than 2 rows\033[0m\n", 2);
	}
	if (err)
	{
		ft_gnl_lstclear(head);
		free(map_data);
		exit (0);
	}
}
