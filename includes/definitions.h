/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 17:01:37 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/02 05:29:55 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

/*
** Used to store mlx basic data
** img is received from mlx_new_image; addr is from mlx_get_data_addr
** lines is not required, but is there to remember stuff when needed.
*/
typedef struct s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					wid;
	int					hei;
	void				*mlx_ptr;
	void				*win_ptr;
	struct s_map_data	*map_data;
}				t_data;

/*
** saves all relevant map information;
** stores heigh and color values according to map coordinates:
** hc[2][5][1] refers to color of the 3rd point in the 6th line;
** rows and line variables are there to make shit easier for us;
*/
typedef struct s_map_data
{
	int				***yxhc;
	struct s_points	**points;
	int				rows;
	int				lines;
	int				max_height;
	int				min_height;
	int				def_min_color;
	int				def_max_color;
}				t_map_data;

/*
** stores transformed map coordinates
** a bit of redundancy from yxhc, but saved as structs to fit all those floats.
** supposed to prevent heisenbugs (not really, just a lazy way not to refactor)
*/
typedef struct s_points
{
	float	x;
	float	y;
	float	z;
	int		color;
}				t_points;

/*
** simple linked list data structure to store read values from map file;
** while one -could- not use it, I couldn't think of a better way;
** 	char *line;
**	struct s_gnl_list *next;
*/
typedef struct s_gnl_list
{
	char				*line;
	struct s_gnl_list	*next;
}				t_gnl_list;

/*
** stores xyhc values from 2 points and use them to draw a fucking line :S
*/
typedef struct s_ln_in
{
	int		x1;
	int		y1;
	int		h1;
	int		x2;
	int		y2;
	int		h2;
	int		color1;
	int		color2;
	t_data	img;
}				t_ln_in;

/*
** reworks ln_in data into smaller more workable chunks
*/
typedef struct s_brese
{
	int		dx;
	int		dy;
	int		adx;
	int		ady;
	int		sx;
	int		sy;
	int		k;
	int		i;
	int		color;
}				t_brese;

typedef struct s_color
{
	int	c1r;
	int	c1g;
	int	c1b;
	int	c2r;
	int	c2g;
	int	c2b;
	int	steps;
	int	r_delta;
	int	g_delta;
	int	b_delta;
	int	ret;
}				t_color;

# define RED_MAX 0x00ff0000
# define GREEN_MAX 0x0000ff00
# define BLUE_MAX 0x000000ff
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define X_WEIGHT 0.25
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# define KEY_ESC 65307
# define KEY_Q 113
# define KEY_E 101
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_R 114
# define KEY_F 102
# define KEY_Z 122
# define KEY_C 99
# define KEY_I 105
# define KEY_O 111
# define KEY_P 122
# define KEY_SPACE 32
# define COS45 0.52532198882
# define SIN45 0.85090352453
# define RED_X 17
# ifndef X_KEYPRESS
#  define X_KEYPRESS 2
# endif

#endif
