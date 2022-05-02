/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 08:49:25 by hmochida          #+#    #+#             */
/*   Updated: 2022/01/03 19:03:40 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map_data	*init_map(char *varg, t_map_data *map_data);
static void			get_map_data(t_map_data *map_data, t_gnl_list *head);
static void			count_xy(t_map_data *map_data, t_gnl_list *head);

/*
** initializes map handling sequence
*/
t_map_data	*get_map(char *varg)
{
	t_map_data	*map_data;

	map_data = malloc (sizeof(t_map_data));
	ft_putstr_fd ("Loading map.\n", 1);
	cfg_get_default_color(map_data);
	map_data = init_map(varg, map_data);
	ft_putstr_fd ("\033[32;1mMap loaded successfully.\033[0m\n", 1);
	return (map_data);
}

/*
**
*/
static t_map_data	*init_map(char *varg, t_map_data *map_data)
{
	t_gnl_list	*head;
	int			fd;
	int			i;

	map_data->lines = 0;
	fd = open(varg, O_RDONLY);
	head = ft_gnl_lstnew(fd);
	i = 1;
	while (i)
	{
		map_data->lines++;
		i = ft_gnl_lstpopulate(fd, &head);
	}
	close(fd);
	ft_putstr_fd ("Validating map.\n", 1);
	check_empty_map(map_data, head);
	head = lstclean_gnl_newlines(head);
	get_map_data(map_data, head);
	return (map_data);
}

/*
** transforms lines inside t_gnl_list into xy arrays inside map_data;
** off with their t_gnl_list *heads aftwerwads;
*/
static void	get_map_data(t_map_data *map_data, t_gnl_list *head)
{
	count_xy(map_data, head);
	check_if_only_one_y_or_x (map_data, head);
	check_lines_len(map_data, head);
	check_for_wild_comma(map_data, head);
	check_solo_hex(map_data, head);
	check_for_letters(map_data, head);
	ft_putstr_fd("Initializing map.\n", 1);
	init_yxhc(map_data, head);
	ft_gnl_lstclear(head);
}

/*
** gets map_data->line and map_data->rows;
*/
static void	count_xy(t_map_data *map_data, t_gnl_list *head)
{
	t_gnl_list	*temp;
	int			i;

	map_data->lines = 0;
	map_data->rows = 0;
	temp = head;
	i = 0;
	while (temp)
	{
		if (temp->line[0] != '\n')
			map_data->lines++;
		temp = temp->next;
	}
	while (head->line[i] && head->line[i] != '\n')
	{
		while (ft_isspace_nonl(head->line[i]) || head->line[i] == '-')
		i++;
		if (head->line[i] == '\n' || head->line[i] == '\0')
			break ;
		while (head->line[i] && !(ft_isspace_nonl(head->line[i])
				&& head->line[i] != '\n'))
		i++;
		map_data->rows++;
	}
}
