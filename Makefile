#naming
NAME = fdf
MLX = libmlx_Linux.a
LIBFT = libft.a

#pathing
LFT_PATH = ./libraries/libft/
MLX_PATH = ./libraries/minilibx-linux/
INCLUDES = ./includes/
SRCDIR = ./src/

#sauce code - yummy.
SRC = $(SRCDIR)fdf.c \
$(SRCDIR)ft_mlx_putpix.c \
$(SRCDIR)ft_mlx_putln.c \
$(SRCDIR)ft_iabs.c \
$(SRCDIR)ft_isspace_nonl.c \
$(SRCDIR)ft_atoihex.c \
$(SRCDIR)get_color.c \
$(SRCDIR)errors_arg.c \
$(SRCDIR)errors_map.c \
$(SRCDIR)errors_map1.c \
$(SRCDIR)errors_map_utils.c \
$(SRCDIR)errors_map_utils1.c \
$(SRCDIR)errors_common.c \
$(SRCDIR)get_next_line.c \
$(SRCDIR)get_next_line_utils.c \
$(SRCDIR)lst_utils0.c \
$(SRCDIR)lst_utils1.c \
$(SRCDIR)map_parser.c \
$(SRCDIR)map_parser_utils.c \
$(SRCDIR)map_parser_utils1.c \
$(SRCDIR)atoi_er.c \
$(SRCDIR)cfg.c \
$(SRCDIR)init_mlx_data.c \
$(SRCDIR)ft_mlx_event_handler.c \
$(SRCDIR)ft_mlx_keymap.c \
$(SRCDIR)key_esc.c \
$(SRCDIR)render.c \
$(SRCDIR)points.c \
$(SRCDIR)exit_seq.c \
$(SRCDIR)exit_seq_utils.c \
$(SRCDIR)matrix_ops.c \
$(SRCDIR)matrix_ops1.c \
$(SRCDIR)get_def_color.c

OBJ = $(notdir $(SRC:%.c=%.o))

#compilation
CF = -Wall -Wextra -Werror -O3
CC = cc
MLX_CF = -lft -lm -lbsd -lmlx -lXext -lX11 
CFI = -I $(INCLUDES)

#common commands
RM =rm -f

#rules
all: $(NAME) meme

$(NAME): $(OBJ) $(LIBFT) $(MLX)  
	@printf "\n$(CY)==== LINKING SHIT TOGETHER ====$(RC)\n"
	$(CC) $(CF) -o $(NAME) $(OBJ) -L$(LFT_PATH) -L$(MLX_PATH) $(MLX_CF) $(CFI)
	@printf "$(GR)==== ENJOY! ====$(RC)\n\n"

$(OBJ): $(SRC) 
	@printf "\n$(CY)==== COMPILING SRCs ====$(RC)\n"
	$(CC) $(CF) -g -c $(CFI) $(SRC)
	@printf "$(GR)==== COMPILED! ====$(RC)\n\n"

$(MLX):
	@printf "\n$(CY)==== PRAYING FOR MINILIBX ====$(RC)\n"
	make -C $(MLX_PATH)
	@printf "$(GR)==== MINILIBX DONEZOR ====$(RC)\n\n"

$(LIBFT):
	@printf "\n$(GR)==== MAKING SACRIFICES TO LIBFT! ====$(RC)\n"
	make -C $(LFT_PATH)
	@printf "$(GR)==== LIBFT SUMMONED! ====$(RC)\n\n"

clean:
	@printf "\n$(YE)==== REMOVING BLOODSTAINS FROM LIBFT ====$(RC)\n"
	make clean -C $(LFT_PATH)
	@printf "$(GR)==== LIBFT IS NOW CLEAN ====$(RC)\n\n"
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	@printf "\n$(YE)==== CLEAN ALL THE THINGS! ====$(RC)\n"
	$(RM) $(NAME) $(BONUS_OBJ)
	@printf "\n$(GR)==== ALL the things...? ====$(RC)\n"
	make fclean -C $(LFT_PATH)
	@printf "\n$(YE)==== PURGING THE MINILIBX HERESY! ====$(RC)\n"
	make clean -C $(MLX_PATH)
	@printf "$(GR)==== MINILIBX IS NO MORE! ====$(RC)\n\n"

re: fclean all

git: fclean
	git add -A
	git commit -m "update"
	git push

run: $(NAME)
	valgrind ./fdf maps/test_maps/42.fdf

norm:
	norminette ./includes
	norminette ./src
	norminette ./libraries/libft

.PHONY: clean fclean re all bonus

#things you dont need to look at if you dont want to.

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

meme:
			@echo "                             ▄██▄"
			@echo "                             ▀███"
			@echo "                                █"
			@echo "               \e[0;93m▄▄▄▄▄\e[0m            █"
			@echo "              \e[0;93m▀▄    ▀▄\e[0m          █"
			@echo "          ▄▀▀▀▄ \e[0;93m█\e[0m▄▄▄▄\e[0;93m█\e[0m▄▄ ▄▀▀▀▄  █      \e[1;95;7mCOMPILE\e[0m"
			@echo "         █  ▄  █        █   ▄ █ █      \e[1;92;7m  ALL  \e[0m"
			@echo "         ▀▄   ▄▀        ▀▄   ▄▀ █      \e[1;95;7m  THE  \e[0m"
			@echo "          █▀▀▀            ▀▀▀ █ █      \e[1;95;7mTHINGS!\e[0m"
			@echo "          █                   █ █"
			@echo "▄▀▄▄▀▄    █  ▄█▀█▀█▀█▀█▀█▄    █ █"
			@echo "█▒▒▒▒█    █  █████████████▄   █ █"
			@echo "█▒▒▒▒█    █  ██████████████▄  █ █"
			@echo "█▒▒▒▒█    █   ██████████████▄ █ █"
			@echo "█▒▒▒▒█    █    ██████████████ █ █"
			@echo "█▒▒▒▒█    █   ██████████████▀ █ █"
			@echo "█▒▒▒▒█   ██   ██████████████  █ █"
			@echo "▀████▀  ██▀█  █████████████▀  █▄█"
			@echo "  ██   ██  ▀█  █▄█▄█▄█▄█▄█▀  ▄█▀"
			@echo "  ██  ██    ▀█             ▄▀\e[0;95m▓\e[0m█"
			@echo "  ██ ██      ▀█▀▄▄▄▄▄▄▄▄▄▀▀\e[0;95m▓▓▓\e[0m█"
			@echo "  ████        █\e[0;95m▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\e[0m█"
			@echo "  ███         █\e[0;95m▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\e[0m█"
			@echo "  ██          █\e[0;95m▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\e[0m█"
			@echo "  ██          █\e[0;95m▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\e[0m█"
			@echo "  ██         ▐█\e[0;95m▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\e[0m█"
			@echo "  ██        ▐█\e[0;95m▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\e[0m█"
			@echo "  ██       ▐█\e[0;95m▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\e[0m█▌"
			@echo "  ██      ▐█\e[0;95m▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\e[0m█▌"
			@echo "  ██     ▐█\e[0;95m▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\e[0m█▌"
			@echo "  ██    ▐█\e[0;95m▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\e[0m█▌"


#ascii art was salvaged and recolored from a random crappy website.
#It is based on actually good art.
#Allie Brosh is quite proficient at drawing and a really good writer
#take a look at it at https://hyperboleandahalf.blogspot.com/