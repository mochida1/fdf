#targets
NAME = fdf

LIBFT = ./libraries/libft/libft.a
MLX_LIB = ./libraries/minilibx-linux/libmlx.a


INCLUDES = -I . -I mlx -I Libft

CC = clang
AR = ar
RM = rm -f

CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
ARFLAGS = rcs
MLX = -l Xext -l X11 -l m -l bsd

#naming
SRC = fdf.c \
	ft_mlx_putpix.c \
	ft_mlx_putln.c \
	ft_iabs.c \
	ft_isspace_nonl.c \
	ft_atoihex.c \
	get_color.c \
	errors_arg.c \
	errors_map.c \
	errors_map1.c \
	errors_map_utils.c \
	errors_map_utils1.c \
	errors_common.c \
	get_next_line.c \
	get_next_line_utils.c \
	lst_utils0.c \
	lst_utils1.c \
	map_parser.c \
	map_parser_utils.c \
	map_parser_utils1.c \
	atoi_er.c \
	cfg.c \
	init_mlx_data.c \
	ft_mlx_event_handler.c \
	ft_mlx_keymap.c \
	key_esc.c \
	render.c \
	points.c \
	exit_seq.c \
	exit_seq_utils.c \
	matrix_ops.c \
	matrix_ops1.c \
	get_def_color.c

OBJECTS = $(SRC:.c=.o)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJECTS)
			make all -C ./libraries/libft
			make all -C ./libraries/minilibx-linux/
			$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX_LIB) $(MLX) -o $(NAME)

clean:
			$(RM) $(OBJECTS)
			make clean -C ./libraries/libft
			make clean -C ./libraries/minilibx-linux/

fclean:		clean
			$(RM) $(NAME)
			make -C ./libraries/libft fclean
norm:
	norminette ./includes
	norminette ./*.c
	norminette ./*.h
	norminette ./libraries/libft

run: all
	valgrind ./fdf maps/test_maps/42.fdf

re: 		fclean all