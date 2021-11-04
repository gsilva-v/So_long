NAME = so_long

CC = clang

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

PATH_SRC = ./src/
PATH_GNL = $(PATH_SRC)gnl/
PATH_MAP = $(PATH_SRC)map/
PATH_UTILS = $(PATH_SRC)utils/
PATH_GAME = $(PATH_SRC)game/
PATH_ERROR = $(PATH_SRC)errors/
PATH_OBJS = ./objs/
PATH_MLX = ./mlx/

MLX = $(PATH_MLX)libmlx.a

LFT = $(PATH_LFT)libft.a

SRCS= $(PATH_MAP)size_map.c $(PATH_MAP)check_map.c \
		$(PATH_MAP)savemap.c $(PATH_MAP)check_more.c $(PATH_MAP)init_imgs.c	\
		$(PATH_GNL)get_next_line.c $(PATH_GNL)get_next_line_utils.c\
		$(PATH_UTILS)ft_strdup.c $(PATH_UTILS)ft_strlen.c $(PATH_UTILS)ft_itoa.c\
		$(PATH_GAME)init.c $(PATH_GAME)window_function.c $(PATH_GAME)render_map.c\
		$(PATH_GAME)moves.c $(PATH_GAME)reset_game.c $(PATH_GAME)print_anything.c\
		$(PATH_ERROR)messages.c

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRCS))

INCLUDE = -I ./

MLXFLAGS = -L $(PATH_MLX) -lmlx -Ilmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[1;35mCompiling Game\033[0m"
	@$(CC) $(CFLAGS) ./src/so_long.c $(OBJS) $(MLXFLAGS) -o $(NAME)
	@echo "\033[1;32mREADY TO LAUNCH\033[0m"

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)map
	@mkdir -p $(PATH_OBJS)gnl
	@mkdir -p $(PATH_OBJS)utils
	@mkdir -p $(PATH_OBJS)errors
	@mkdir -p $(PATH_OBJS)game
	@$(CC) $(CFLAGS) -I. -c $< -o $@
	
bonus: all

clean:
	@echo "\033[1;33mCleaning objects\033[0m"
	@$(RM) $(PATH_OBJS)
	@echo "\033[1;32mDone!\033[0m"
	
fclean: clean
	@$(RM) so_long
	@echo  "\033[1;33mCleaning all\033[0m"

re: fclean all

.PHONY: all clean bonus fclean re 