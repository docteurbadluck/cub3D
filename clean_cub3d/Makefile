CC = cc

LIBX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm
LIBFT = -Llibft -lft

CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	layer_1/map.c layer_1/player.c layer_1/raycaster.c \
	layer_2/update_vision.c layer_2/update_player.c layer_2/update_game.c \
	layer_4/mlx_controller.c layer_4/mlx_displayer.c \
	layer_4/mlx_close.c layer_4/mlx_init.c layer_4/mlx_event.c

HEADERS = layer_1/map.h layer_1/player.h layer_1/raycaster.h \
	layer_2/update_vision.h layer_2/update_player.h layer_2/update_game.h \
	layer_3/controller.h layer_3/displayer.h \
	layer_4/mlx_context.h layer_4/mlx_controller.h layer_4/mlx_displayer.h game_context.h

BUILD_DIR = build
OBJ_FILES = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))
NAME = $(BUILD_DIR)/cub3d

# Default target
all: lib create-dir $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBX) $(LIBFT) -o $(NAME)

# Compile .c files to .o inside build/
$(BUILD_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

lib:
	@make -C libft > /dev/null 2>&1
	@make -C minilibx-linux > /dev/null 2>&1

create-dir:
	@mkdir -p $(BUILD_DIR)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lib create-dir