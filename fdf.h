/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 04:17:05 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/02 11:33:25 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** INCLUDES INCLUSIONS
*/
# include "./libraries/libft/libft.h"
# include "./libraries/minilibx-linux/mlx.h"
# include "./libraries/minilibx-linux/mlx_int.h"
# include "./includes/definitions.h"
# include "./includes/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

int			ft_atoihex(const char *str);
int			ft_isspace_nonl(char c);
char		*get_next_line(int fd);
t_gnl_list	*ft_gnl_lstnew(int fd);
void		ft_gnl_lstadd_back(t_gnl_list **lst, t_gnl_list *new);
t_gnl_list	*ft_gnl_lstlast(t_gnl_list *lst);
int			ft_gnl_lstpopulate(int fd, t_gnl_list **start);
void		ft_gnl_lstclear(t_gnl_list *lst);
t_map_data	*get_map(char *varg);
t_gnl_list	*lstclean_gnl_newlines(t_gnl_list *head);
void		init_yxhc(t_map_data *map_data, t_gnl_list *head);
void		iterate_atoi(t_map_data *map_data, t_gnl_list *head);
void		iterate_atoi_x(t_map_data *map_data, t_gnl_list *head, int y);
int			check_if_height(const char *str);
int			get_map_color(const char *str);
int			advance_atoiiter_counter(const char c);
void		set_minmax_height(t_map_data *map_data, int height);

void		free_yxhc(t_map_data *map_data);
void		check_args(int argc, char **argv);
void		check_empty_map(t_map_data *map_data, t_gnl_list *head);
void		check_lines_len(t_map_data *map_data, t_gnl_list *head);
int			check_invalid_char(char c, t_map_data *map_data, t_gnl_list *head);
int			ermap_get_count(t_map_data *map_data, t_gnl_list *temp,
				t_gnl_list *head);
void		errmap_check_count(int count, t_map_data *map_data,
				t_gnl_list *head);
void		errmap_check_hexfmt(char *str, t_map_data *map_data,
				t_gnl_list *head);
int			convert_af(char str);
void		free_some_pointers(t_map_data *map_data, t_gnl_list *head);
int			atoi_er(const char *str);
void		check_for_wild_comma(t_map_data *map_data, t_gnl_list *head);
void		check_if_only_one_y_or_x(t_map_data *map_data, t_gnl_list *head);
void		check_solo_hex(t_map_data *map_data, t_gnl_list *head);
void		check_solo_hex_err(t_map_data *map_data, t_gnl_list *head);
void		check_for_letters(t_map_data *map_data, t_gnl_list *head);
void		check_for_letters_err(t_map_data *map_data, t_gnl_list *head);

void		cfg_get_default_color(t_map_data *map_data);
void		cfg_get_wid_hei(t_data *img);
void		ft_mlx_putpix(t_ln_in *ln_in, int color);
int			ft_mlx_putln(t_ln_in ln_in);
int			get_color(t_ln_in ln_in, t_brese brese);
int			get_def_color(t_map_data *map_data, int height);
int			ft_iabs(int x);
void		init_mlx_data(t_data *img, char **argv);
void		init_points(t_data *img);
void		get_points(t_data *img);
void		copy_points(t_data *img, int ix, int iy);
void		point_wrapper(t_data *img);

void		event_handler(t_data *img);
int			key_press(int keycode, t_data *img);
int			keymap00(int keycode, t_data *img);
int			keymap01(int keycode, t_data *img);
int			keymap02(int keycode, t_data *img);
void		key_esc(t_data *img);

void		rotate45(t_map_data *map_data);
void		scale_y_to_half(t_map_data *map_data);
void		matrix_ops(t_data *img);
void		translate_to_center(t_map_data *map_data, int wid, int hei);
void		equi_scale(t_map_data *map_data, float factor);
int			render(t_data *img);
void		update_line(t_ln_in *line, t_points pt1, t_points pt2);

void		exit_prerender(t_data *img);
void		exit_prerender01(t_data *img, int row_index);
void		free_points(t_data *img, int row_index);
void		free_all_points(t_data *img);

int			red_x_close(t_data *img);

#endif
