NAME= so_long

CC = clang

PATH_SRC = ./src/
PATH_GNL = $(PATH_SRC)gnl/
PATH_MAP = $(PATH_SRC)map/
PATH_MLX = ./mlx/
PATH_UTILS = $(PATH_SRC)utils/
PATH_GAME = $(PATH_SRC)game/
PATH_OBJS = ./objs/

MLX = $(PATH_MLX)libmlx.a

LFT = $(PATH_LFT)libft.a

SRCS= $(PATH_MAP)size_map.c $(PATH_MAP)check_map.c $(PATH_MAP)check_ber.c\
		$(PATH_MAP)savemap.c $(PATH_MAP)validates.c $(PATH_MAP)init_imgs.c	\
		$(PATH_GNL)get_next_line.c $(PATH_GNL)get_next_line_utils.c\
		$(PATH_UTILS)ft_strdup.c $(PATH_UTILS)ft_strlen.c $(PATH_UTILS)ft_strjoin.c\
		$(PATH_UTILS)ft_split.c\
		$(PATH_GAME)init.c $(PATH_GAME)open_window.c $(PATH_GAME)render_map.c

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRCS))

INCLUDE = -I ./

MLXFLAGS = -I $(PATH_MLX) -L $(PATH_MLX) -lmlx -Ilmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(PATH_MLX)
	$(CC) -g $(MLXFLAGS) ./src/so_long.c $(OBJS) $(MLX) -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)map
	@mkdir -p $(PATH_OBJS)gnl
	@mkdir -p $(PATH_OBJS)utils
	@mkdir -p $(PATH_OBJS)errors
	@mkdir -p $(PATH_OBJS)game
	$(CC) -I. -c $< -o $@

clean:
	rm -rf so_long

test:
		$(CC) $(MLXFLAGS) $(INCLUDE) $(PATH_SRC)so_long.c $(SRCS) ./mlx/libmlx_Linux.a -o so_long